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


ll solve(ll curr,ll n,vector<pair<ll,ll>> &dp)
{
	if(curr==n)
		return 0;
	if(!(dp[curr].first==-1 && dp[curr].second==-1))
		return dp[curr].first;
	dp[curr].first=1+solve(curr+1,n,dp);
	dp[curr].second=1;
	if((curr*2)<=n)
	{
		ll temp =1+solve(curr*2,n,dp);
		if(temp<dp[curr].first)
		{
			dp[curr].first=temp;
			dp[curr].second=2;
		}
	}
	if((curr*3)<=n)
	{
		ll temp =1+solve(curr*3,n,dp);
		if(temp<dp[curr].first)
		{
			dp[curr].first=temp;
			dp[curr].second=3;
		}
	}
	return dp[curr].first;
}

int main()
{
	ll t,n,k,i,j,m;
	boost();
	cin>>n;
	vector<pair<ll,ll>> dp(n,{-1,-1}); 
	cout<<solve(1,n,dp)<<endl;
	ll curr =1;
	cout<<"1 ";
	while(curr!=n)
	{
		if(dp[curr].second==1)
			curr=curr+1;
		else
		if(dp[curr].second==2)
			curr=curr*2;
		else
			curr=curr*3;
		cout<<curr<<" ";
	}
	cout<<endl;
	return 0;
}