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
	ll t,n,k,i,j,m;
	boost();
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		ll ans=0;
		j=str.size()-1;
		char ch='0';
		for(i=0;i<str.size()-1;i++)
		{
			if(str[i]>str[i+1])
			{
				ch=str[i];
				j=i;
				break;
			}
		}
		str.erase(str.begin()+j);
		while(str.size()>1 && str[0]=='0')
			    str.erase(str.begin());
		for(i=0;i<str.size();i++)
		{
			ans=ans*10+(str[i]-48);
		}
		cout<<ans<<endl;
	}
	return 0;
}