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
	ll t,n,k,i,c=0;
	bool v[200005];
	boost();
	string str;
	cin>>n>>str;
	for(i=0;i<n;i++)
		v[i]=true;
	for(i=0;i<n;i+=2)
	{
		if(str[i]==str[i+1])
		{
			v[i]=false;
			i--;
			c++;
		}
	}
	if((n-c)%2!=0)
	{
		c++;
		for(i=n-1;i>=0;i--)
			if(v[i]==true)
			{
				v[i]=false;
				break;
			}
	}
	if(c==n)
	{
		cout<<c<<endl<<endl;
	}
	else
	{
		cout<<c<<endl;
		for(i=0;i<n;i++)
		{
			if(v[i])
				cout<<str[i];
		}
		cout<<endl;
	}
	return 0;
}