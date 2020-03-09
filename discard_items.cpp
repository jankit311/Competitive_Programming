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
	ll t,n,k,i,j,m;
	boost();
	cin>>n>>m>>k;
	ll arr[m];
	for(i=0;i<m;i++)
	{
		cin>>arr[i];
	}
	ll ans=0;
	i=0;
	ll start=1,end=k,s=0;
	while(i<m)
	{
		ll c=0;
		while(i<m && (arr[i]-s)>=start && (arr[i]-s)<=end)
		{
			i++;
			c++;
		}
		if(c==0)
		{
			ll temp = arr[i]-s;
			if(temp%k==0)
				start=temp-(k-1);
			else
				start=temp - (temp%k-1);
			end=start+(k-1);
			continue;
		}
		s+=c;
		ans++;
	}
	cout<<ans<<endl;
	return 0;
}