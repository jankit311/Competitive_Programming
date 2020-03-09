#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,x;

	cin>>n;

	vector<int> adj[n+1];
	for(int i=1;i<n;i++)
	{
		cin>>x;

		adj[x].push_back(i+1);
	}

	for(int i=1;i<=n;i++)
	{
		int count=0;
		for(int j=0;j<adj[i].size();j++)
		{

			if(adj[adj[i][j]].size()==0)
				count++;
		}
		if(adj[i].size()>0 && count<3)
		{
			cout<<"No"<<endl;
			return 0;
		}
	}
	cout<<"Yes"<<endl;
	return 0;
}