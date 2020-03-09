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
	cin>>n>>m;
	vector<vector<pair<ll,ll>>> adj(n+1);
	vector<pair<ll,pair<ll,ll>>> ans;
	ll arr[n+1];
	memset(arr,0,sizeof(arr));
	while(m--)
	{
		ll u,v,d;
		cin>>u>>v>>d;
		arr[u]-=d;
		arr[v]+=d;
		adj[v].push_back({u,d});
	}
	vector<ll> pos,neg;
	for(i=1;i<=n;i++)
	{
		if(arr[i]>0)
			pos.push_back(i);
		else
		if(arr[i]<0)
			neg.push_back(i);
	}
	j=0;
	for(i=0;i<pos.size();i++)
	{
		while(arr[pos[i]]>0)
		{
			k=min(arr[pos[i]],-arr[neg[j]]);
			arr[pos[i]]-=k;arr[neg[j]]+=k;
			ans.push_back({pos[i],{neg[j],k}});
			if(arr[neg[j]]==0)
			{
				j++;
			}
		}
	}
	cout<<ans.size()<<endl;
	for(i=0;i<ans.size();i++)
		cout<<ans[i].second.first<<" "<<ans[i].first<<" "<<ans[i].second.second<<endl;
	return 0;
}