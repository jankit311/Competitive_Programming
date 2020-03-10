// A modular inverse based solution to 
// compute nCr % p 
#include<bits/stdc++.h> 
using namespace std;
#define ll unsigned long long int 
const ll mod = 1e9+7;
ll fac[mod];
ll n=mod; 
int power(ll x, ll y, ll p) 
{ 
	int res = 1;

	x = x % p;  

	while (y > 0) 
	{  
		if (y & 1) 
			res = (res*x) % p;  
		y = y>>1;  
		x = (x*x) % p; 
	} 
	return res; 
}  
ll modInverse(ll n, ll p) 
{ 
	return power(n, p-2, p); 
}  
ll nCrModPFermat(ll n, ll r, ll p) 
{ 
if (r==0) 
	return 1;  

	return (fac[n]* modInverse(fac[r], p) % p * 
			modInverse(fac[n-r], p) % p) % p; 
} 
void boost()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	fac[0] = 1; 
	for (ll i=1 ; i<=n; i++) 
		fac[i] = fac[i-1]*i%p; 
}

int main() 
{  
	boost();
	ll p = mod,r,n,i;
	ll t;
	cin>>t;
	for(i=0;i<t;i++)
	{
		cin>>n;
		cin>>r;
		cout<<(nCrModPFermat(n,r,p)%p)*(power(2,n-r,p)%p)%p<<endl;
	}

	return 0; 
} 
