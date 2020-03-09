#include<bits/stdc++.h>
using namespace std;
#define ll int 
double dp[3000][3000],p[3000];
ll n;

void boost()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

double solve(ll i,ll ch)
{
	//cout<<ch<<endl;
	if(i==n+1)
	{
		if(ch<=(n/2))
			return 0;
		else
			return 1;
	}
	if((ch+(n-i)+1)<=(n/2))
		return 0;
	if(dp[i][ch]!=-1.0)
		return dp[i][ch];
	double res1=0.0,res2=0.0,temp=0.0;
	temp = solve(i+1,ch)*(1-p[i]);
	if(temp>res1)
		res1=temp;
	temp = solve(i+1,ch+1)*p[i];
	if(temp>res2)
		res2=temp;
	return dp[i][ch]=(res2+res1);
}

int main()
{
	ll i,j;
	boost();
	cin>>n;
	cout.precision(10);
	for(i=1;i<=n;i++)
	{
		for(j=0;j<=n;j++)
			dp[i][j]=-1.0;
	}
		
	for(i=1;i<=n;i++)
	{
		cin>>p[i];
		//cout<<p[i]<<endl;
	}
	cout<<solve(1,0)<<endl;
	return 0;
}