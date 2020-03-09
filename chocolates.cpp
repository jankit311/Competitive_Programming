#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
	ll i,n,arr[200005],c=0,mini;

	scanf("%lld",&n);

	for(i=0;i<n;i++)
		scanf("%lld",&arr[i]);
	c+=arr[n-1];
	mini=arr[n-1]-1;
	for(i=n-1;i>=0;i--)
	{
		if(mini>0)
		{
			c+=min(arr[i],mini)
		}
		mini=min(arr[i],mini)-1;
	}
	printf("%lld\n",c);
	return 0;
}