#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll unsigned long long int 


ll power(ll a ,ll b)
{
	ll res = 1;
	if(b == 0)
		return 1;
	if(b == 1)
		return a;
	while(b>0)
	{
		if(b & 1)
			res = ((res%mod) * (a%mod))%mod;
		b = b >> 1;
		a = ((a%mod) * (a%mod))%mod;
	}
	return res%mod;
}

ll gcd(ll a,ll b)
{
	if(a%b==0)
		return b;
	return gcd(b,a%b);
}


int main()
{
	ll n,m,k,t,i;

	scanf("%llu",&t);

	while(t--)
	{
		ll ans,num,denom;
		scanf("%llu %llu %llu",&n,&k,&m);

		if(m%2!=0)
		{
			ans = (((power(n,m/2+1)%mod - power(n-1,m/2+1)%mod + mod)%mod)*(power(n,((m/2+1)*(mod-2)))%mod))%mod;
		}
		else
		if(m%2==0)
		{
			 num = ((power(n,m/2)%mod)*((n+k)%mod))%mod - ((power(n-1,m/2)%mod)*((n+k-1)%mod))%mod + mod;
			 num = num%mod;

			 denom = (power(n,m/2*(mod-2))*(power(n+k,mod-2)%mod))%mod;

			 ans = (num*denom)%mod;
		}
		printf("%llu\n",ans);
	}
	return 0;
}
