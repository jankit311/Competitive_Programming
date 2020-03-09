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
	ll t,n,k,i,x,j;
	boost();
	cin>>t;
	while(t--)
	{
		cin>>n;
		ll ans=1,flag=0;
		vector<ll> v,u;
		for(i=0;i<n;i++)
		{
			cin>>x;
			v.push_back(x);
		}
		sort(v.begin(),v.end());
		ans=v[0]*v[v.size()-1];
		for(i=2;i*i<=ans;i++)
		{
			if(ans%i==0)
			{
				u.push_back(i);
				if(i!=(ans/i))
					u.push_back(ans/i);
			}
		}
		sort(u.begin(),u.end());
		if(u.size()!=v.size())
		{
			cout<<"-1"<<endl;
			continue;
		}
		for(i=0;i<u.size();i++)
		{
			if(u[i]!=v[i])
				break;
		}
		if(i==u.size())
			cout<<ans<<endl;
		else
			cout<<"-1"<<endl;
	}
	return 0;
}