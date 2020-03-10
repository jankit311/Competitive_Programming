#include<bits/stdc++.h>
using namespace std;
long long int dp[2001][2001];

long long int solve(int i,int last,deque<int> colors,deque<int> delic,int c,int k)
{
	if(i==colors.size())
		return last;
	if(dp[i][last]!=-1)
		return dp[i][last];
	if(colors.at(i)>=(c-k) && colors.at(i)<=(c+k))
	{
		int res1=solve(i+1,0,colors,delic,c,k);
		int res2=solve(i+1,last+delic.at(i),colors,delic,c,k);
		dp[i][last]=max(res1,res2);
	}
	else
	dp[i][last]=solve(i+1,last,colors,delic,c,k);
	
	return dp[i][last];
}

int main()
{
	int q,k,i,b,d,c,ans=0,max,res,prev,count,max_count,idx,res_idx;

	cin>>q>>k;
	deque<int> colors;
	deque<int> delic;
	
	for(i=0;i<q;i++)
	{
		cin>>b;
		if(b==1)
		{
			cin>>c>>d;

			c=c^ans;
			colors.push_front(c);
			delic.push_front(d);
		}
		else
		if(b==2)
		{
			cin>>c>>d;

			c=c^ans;
			colors.push_back(c);
			delic.push_back(d);
		}
		else
		{
			memset(dp,-1,sizeof(dp));
			cin>>c;
			c=c^ans;

			ans = solve(0,0,colors,delic,c,k);
			cout<<ans<<endl;
		}
	//	cout<<c<<endl;
	}
	return 0;
}