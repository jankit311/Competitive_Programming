#include<bits/stdc++.h>
using namespace std;
int C[1001]; 

int nCrModp(int n, int r, int p) 
{ 
    C[0] = 1; 
    for (int i = 1; i <= n; i++) 
    { 
        
        for (int j = min(i, r); j > 0; j--) 
            C[j] = (C[j] + C[j-1])%p; 
    } 
} 
int main()
{
	long long int t,n,a[10001],i,ans,p=1000000007;

	cin>>t;

	while(t--)
	{
		cin>>n;
		memset(C, 0, sizeof(C)); 
		nCrModp(n,n,p);
		ans=0;
		for(i=1;i<=n;i++)
			cin>>a[i];
		sort(a,a+n);
		for(i=1;i<=n;i+=2)
		{
			ans=(ans%p+C[i]%p)%p;
		}
		cout<<ans<<endl;
	}
	return 0;
}