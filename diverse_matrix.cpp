#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mod = 1e9+7;

void boost()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int main()
{
	boost();
	ll t,n,k,i,j,m;
	cin>>n>>m;
	if(n==1 && m==1)
	{
		cout<<"0"<<endl;
		return 0;
	}
	if(m==1)
	{
		for(j=2;j<=n+1;j++)
			cout<<j<<endl;
		return 0;
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
			cout<<i*(n+j)<<" ";
		cout<<endl;
	}
	return 0;
}