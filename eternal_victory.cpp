#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mod = 1e9+7;

vector<vector<pair<ll,ll>>> adj(100005);
vector<bool> visit(100005,false);

void boost()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

pair<ll,ll> dfs(ll i)
{
	visit[i]=true;
	ll ans=0,ret=0;
	vector<ll> v;

	for(ll j=0;j<adj[i].size();j++)
	{
		if(visit[adj[i][j].first]==false)
		{
			pair<ll,ll> p = dfs(adj[i][j].first);
			ll temp = adj[i][j].second+p.second;
			ans+=adj[i][j].second+p.first;
			v.push_back(temp); 
		}
	}

	sort(v.begin(),v.end());

	for(i=0;i<((ll)v.size()-1);i++)
		ans+=v[i];
	if(v.size()>0)
		ret=v[i];

	return {ans,ret};
}

int main()
{
	ll t,n,k,i,j,m,u,v,w;
	boost();
	cin>>n;

	for(i=0;i<n-1;i++)
	{
		cin>>u>>v>>w;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}

	cout<<dfs(1).first<<endl;

	return 0;
}