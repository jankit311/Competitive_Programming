#include<bits/stdc++.h>
using namespace std;

vector<int> adj[100005];
int mx1[100005];
int mx2[100005];
//gayiulfiudh

void maxdepth1(int i,int parent)
{
    int ans=0;
    if(adj[i].size()==1)
    {
    	mx1[i]=-1;
    	return;
    }
	for(int j : adj[i])
	{
		if(j!=parent)
		{
		    maxdepth1(j,i);
			ans = max(ans,1+mx1[j]);
		}
	}
	mx1[i]=ans;
}

void maxdepth2(int i,int parent)
{
	int count=0;
	if(adj[i].size()==1)
	{
		mx2[i]=-1;
		return;
	}
	for(int j : adj[i])
	{
		if(j!=parent)
		{
			if((1+mx1[j])>mx2[i] && (1+mx1[j])<=mx1[i])
			{
				if(mx1[i]==(1+mx1[j]) && count==0)
				{
					count++;
				}
				else
					mx2[i]=1+mx1[j];
			}
			maxdepth2(j,i);
		}
	}
}

int diameter(int i,int parent)
{
	int dia = 0;
	
	/*if(adj[i].size()==1)
		return 0;*/

	for(int j : adj[i])
	{
		if(j!=parent)
		{
			int p;
			p = diameter(j,i);
			dia = max(dia,p);
		}
	}
	dia = max(dia,mx1[i]+mx2[i]+2);
	//cout<<dia<<" ";
	return dia;
}

int main()
{
	int n,i,j,u,v;

	cin>>n;
	
	for(i=1;i<n;i++)
	{
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	memset(mx1,0,sizeof(mx1));
	memset(mx2,0,sizeof(mx2));
	maxdepth1(1,0);
	maxdepth2(1,0);
/*	for(i=1;i<=n;i++)
		cout<<mx2[i]<<" ";
	cout<<endl;
	for(i=1;i<=10;i++)
		cout<<mx1[i]<<" ";
	cout<<endl;*/
	int p;
	p = diameter(1,0);
	cout<<p;
	return 0;
}