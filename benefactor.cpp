#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int> > adj[100005];
int x;

bool equal(pair<int,int> p1,pair<int,int> p2)
{
	if(p1.first==p2.first && p1.second==p2.second)
		return true;
	return false;
}

void dfs(int i,int count,int parent,int& maxcount)
{
	for(pair<int,int> j : adj[i])
	{
		if(j.first!=parent)
		{
			if((count+j.second)>=maxcount)
			{
				maxcount = count+j.second;
				x = j.first;
			}
			dfs(j.first,count+j.second,i,maxcount);
		}
	}
}

int main()
{
	int t,n,i,j,x,y;
	pair<int,int> p;

	cin>>t;

	while(t--)
	{
		cin>>n;

		for(i=1;i<=n;i++)
			adj[i].clear();

		for(i=0;i<n;i++)
		{
			cin>>x>>y>>j;
			p = make_pair(y,j);
			adj[x].push_back(p);
			p = make_pair(x,j);
			adj[y].push_back(p);
		}

		int maxcount = 0;
		int parent = -1;
		dfs(1,0,parent,maxcount);
		dfs(x,0,parent,maxcount);
		cout<<maxcount<<endl;
	}
	return 0;
}