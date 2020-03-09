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

vector< bitset<2005> >adj(2005);
int main()
{
	ll t,n,k,i,j,m,u;
	boost();
	cin>>n>>m>>k;

	for(i=0;i<m;i++)
	{
		cin>>t>>u;
		adj[t][u]=adj[u][t]=1;
	}
	for(i=1;i<n;i++)
	{
		for(j=i+1;j<=n;j++)
			if((adj[i]&adj[j]).count()>=k)
			{
				cout<<"YES"<<endl;
				return 0;
			}
	}
	cout<<"NO"<<endl;
	return 0;
}