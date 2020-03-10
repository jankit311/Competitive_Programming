#include<bits/stdc++.h>
using namespace std;

int main()
{
	int i,n,arr[10005],c=0,j;
	queue<int> q;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		q.push(i);
		scanf("%d",&arr[i]);
	}
	for(i=1;i<=n;i++)
	{
		int tmp = arr[i];
		c++;
		j=i;
		while(j<tmp && j<n)
		{
			j++;
			tmp = max(arr[j],tmp);
		}
		i=j;
	}
	printf("%d\n",c);
	return 0;
}