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

int visit[101];

int main()
{
	ll t,n,k,i,a,b,x,y;
	boost();
	cin>>n>>a>>x>>b>>y;
	int i=0;
	while(a!=x)
	{
		visit[i]=x;
		i++;
		if(a<n)
			a++;
		else
			a=1;
	}
	int j=0;
	while(b!=y)
	{
		if(j<i && visit[i]==b)
		{
			cout<<"YES"<<endl;
			return 0;
		}
		j++;
		if(b>0)
			b--;
		else
			b=n;
	}
	cout<<"NO"<<endl;
	return 0;
}