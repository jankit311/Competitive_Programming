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
	boost();
	ll t,n,k,i,j,m;
	cin>>t;
	while(t--)
	{
		string a,b;
		cin>>a;
		cin>>b;
		map<ll,ll> mm;
		vector<vector<ll>> v(26);
		for(i=0;i<a.size();i++)
		{
			v[a[i]-'a'].push_back(i);
			mm[a[i]-'a']++;
		}
		ll cnt=0,ll last=-1;
		for(i=0;i<b.size();i++)
		{
			if(mm[b[i]-'a']==0)
			{
				cnt=-1;
				break;
			}
			j = upper_bound(v[b[i]-'a'].begin(),v[b[i]-'a'].end(),last)-v[b[i]-'a'];
			if(j==((ll)v[b[i]-'a'].size()))
			{
				cnt++;
				last=v[b[i]-'a'][0];
			}
			else
				last=j;
		}
		cout<<cnt<<endl;

	}
	return 0;
}