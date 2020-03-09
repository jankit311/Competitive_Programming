#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,k,t,i,j,a[1000000];

	cin>>t;

	while(t--)
	{
		cin>>n;
		k=-1;
		for(i=0;i<n;i++)
			cin>>a[i];
		for(i=1;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(a[j]==-1)
					continue;
				else
				if((j%i+1)==a[j])
					continue;
				else
					break;
			}
			if(j==n)
			{
				if(i>k)
					k=i;
			}
		}
		if(k==-1)
			cout<<"impossible\n";
		else
		if(k==n-1)
		{
			for(j=0;j<n;j++)
			{
				if(a[j]==-1)
					continue;
				else
				if((j%n+1)==a[j])
					continue;
				else
					break;
			}
			if(j==n)
			{
				for(j=0;j<n;j++)
				{
					if(a[j]==-1)
						continue;
					else
					if((j%(n+1)+1)==a[j])
						continue;
					else
						break;
				}
				if(j==n)
					cout<<"inf\n";
				else
					cout<<n<<"\n";
			}
			else
				cout<<k<<"\n";
		}
		else
			cout<<k<<"\n";
	}
	return 0;
}
