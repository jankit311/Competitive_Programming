#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mod = 1e9+7;

void boost()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

ll t,n,k,i,j,m,x,y;

ll arr[1001];

ll dp[1001][2];

ll solve(int i,int color)
{
	if(i==m)
		return 0;
	if((m-i)<x)
		return INT_MAX;
	if(color==-1)
	{
		ll res1=0,res2=0,j;
		for(j=i;j<(i+x);j++)
		{
			res1+=(n-arr[j]);
		}
		ll temp=res1;
		res1+=solve(j,0);
		for(j=i+x;j<(i+y) && j<m;j++)
		{
			temp=temp+(n-arr[j]);
			res1=min(res1,temp+solve(j+1,0));
		}
		dp[i][1]=res1;
		for(j=i;j<(i+x);j++)
		{
			res2+=arr[j];
		}
		temp=res2;
		res2+=solve(j,1);
		for(j=i+x;j<(i+y) && j<m;j++)
		{
			temp=temp+(arr[j]);
			res2=min(res2,temp+solve(j+1,1));
		}
		dp[i][0]=res2;
		return min(dp[i][0],dp[i][1]);
	}
	if(dp[i][color]!=-1)
		return dp[i][color];
	ll res=0,j;

	for(j=i;j<(i+x);j++)
	{
		if(color==0)
			res+=arr[j];
		else
			res+=(n-arr[j]);
	}
	ll temp=res;
	res+=solve(j,1-color);
	for(j=i+x;j<m && j<(i+y);j++)
	{
		if(color==0)
			temp=temp+arr[j];
		else
			temp+=(n-arr[j]);
		res=min(res,temp+solve(j+1,1-color));
	}
	dp[i][color]=res;
	return dp[i][color];
}

int main()
{
	
	boost();
	cin>>n>>m>>x>>y;
	memset(arr,0,sizeof(arr));
	memset(dp,-1,sizeof(dp));
	for(i=0;i<n;i++)
	{
		string str;
		cin>>str;
		for(j=0;j<m;j++)
		{
			if(str[j]=='#')
				arr[j]++;
		}
	}

	cout<<solve(0,-1)<<endl;

	return 0;
}