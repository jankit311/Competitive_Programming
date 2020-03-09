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

int main()
{
	ll t,n,k,i,j,m,id,T,curr_t=0;
	boost();
	cin>>k;
	cin>>n;
	map<int,int> mm;
	for(i=0;i<n;i++)
	{
		cin>>t>>id>>T;
		curr_t=T;
		if(t==0 && mm[id]==0)
		{
			mm[id]=k+T;
		}
		else
		if(t==1 && mm[id]>=curr_T)
		{
			mm[id]=T+k;
		}
	}
	ll ans=0;
	for(auto it=mm.begin();it!=mm.end();it++)
	{
		if(*it>curr_T)
			ans++;
	}
	cout<<ans<<endl;
	return 0;
}