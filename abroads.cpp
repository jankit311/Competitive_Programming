#include<bits/stdc++.h>
using namespace std;
#define size 500002

long long int n,m,q,x[size],y[size],pop[size],pop_prev[size],total[size],parent[size],A[size],B[size],ans[size];
int del[size] = {0};
char qtype[size];
multiset<long long int> s;

int find(int a)
{
	if(parent[a] == a)
		return a;
	return parent[a] = find(parent[a]);
}

void Union(int a,int b)
{
	int P,Q;
	P = find(a);
	Q = find(b);
	if(P!=Q)
	{
		s.erase(s.find(total[P]));
		s.erase(s.find(total[Q]));
		total[Q]+=total[P];
		s.insert(total[Q]);
		parent[P] = Q;
	}
}

long long int largestpop()
{
	multiset<long long int>::iterator it = s.end();
	it--;
	return *it;
}

int main()
{
	int i,j;

	scanf("%lld %lld %lld",&n,&m,&q);

	for(i=1;i<=n;i++)
	{
		scanf("%lld",&pop[i]);
	}

	for(i=1;i<=m;i++)
	{
		scanf("%lld %lld",&x[i],&y[i]);
	}

	for(i=1;i<=q;i++)
	{
		scanf(" %c",&qtype[i]);
		if(qtype[i]=='D')
		{
			scanf("%lld",&A[i]);
			del[A[i]]=1;
		}
		else
		{
			scanf("%lld %lld",&A[i],&B[i]);
			pop_prev[i] = pop[A[i]];
			pop[A[i]] = B[i];
		}
	}

	for(i=1;i<=n;i++)
	{
		parent[i]=i;
		total[i]=pop[i];
		s.insert(total[i]);
	}

	for(i=1;i<=m;i++)
	{
		if(del[i]!=1)
			Union(x[i],y[i]);
	}

	ans[q] = largestpop();

	for(i=q;i>=1;i--)
	{
		if(qtype[i]=='D')
			Union(x[i],y[i]);
		else
		{
			int P = find(A[i]);
			s.erase(s.find(total[P]));
			total[P]-=pop[A[i]];
			pop[A[i]]=pop_prev[i];
			total[P]+=pop[A[i]];
			s.insert(total[P]);
		}
		ans[i-1] = largestpop();
	}

	for(i=1;i<=q;i++)
		printf("%lld\n",ans[i]);

	return 0;
}