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
		ll c=0;
		for(i=0;i<str.size();i++)
		{
			if(str[i]=='1')
				c++;
		}
		if(c%2==0)
			cout<<"LOSE"<<endl;
		else
			cout<<"WIN"<<endl;
	}
	return 0;
}