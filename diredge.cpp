#include<bits/stdc++.h>
using namespace std;

struct edge
{
	int u,v;
};

struct ind
{
	int indegree[100001];
	int arr[100001];
};

typedef struct edge EDGE;
EDGE e[100001];
int n,m;

int isSolvable(int k,struct ind res,int *p)
{
	if(k==m && *p==0)
	{
		for(int i=1;i<=n;i++)
			if(res.indegree[i]%2!=0)
				return 0;
		for(int i=0;i<m;i++)
			cout<<res.arr[i]<<" ";
		cout<<endl;
		*p=1;
		return 1;
	}

	if((*p)==1)
		return 1;

	res.arr[k]=0;
	res.indegree[e[k].v]++;
	if(isSolvable(k+1,res,p))
		return 1;
	else
	{
		res.arr[k]=1;
		res.indegree[e[k].v]--;
		res.indegree[e[k].u]++;
		return isSolvable(k+1,res,p);
	}

}
int main()
{
	struct ind res;
	int k,t,i,j;
	cin>>t;

	while(t--)
	{

		cin>>n>>m;
		int count=0;
		memset(res.indegree,0,sizeof(res.indegree));
		memset(res.arr,-1,sizeof(res.arr));

		for(k=0;k<m;k++)
		{
			cin>>i>>j;
			e[k].u=i;
			e[k].v=j;
		}

		if(isSolvable(0,res,&count)==0)
			cout<<-1<<endl;
	}
	return 0;
}