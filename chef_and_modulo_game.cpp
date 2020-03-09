#include<bits/stdc++.h>
using namespace std;

int main()
{
	unsigned long long int n,p,m,t,ans;

	cin>>t;

	while(t--)
	{
		cin>>n>>p;

		if(n%2!=0)
		{
			m = n%((n+1)/2);
			ans = (p-(n/2))*(p-(n/2))+(p-n)*(p-(n/2))+(p-n)*(p-n);
		}
		else
		{
			m = n%((n/2)+1);
			ans = (p-(n/2)+1)*(p-(n/2)+1)+(p-(n/2)+1)*(p-n)+(p-n)*(p-n);
		}
		if(m==0)
			ans = p*p*p;
		cout<<m<<endl;
		cout<<ans<<endl;
	}
	return 0;
}