#include<bits/stdc++.h>
using namespace std;

unsigned long long int count(unsigned long long int mid,unsigned long long int ab[],unsigned long long int a[],unsigned long long int b[],unsigned long long int n)
{
	unsigned long long int i,count=0;
	for(i=0;i<n;i++)
	{
		if(ab[i]>=mid)
		{
			count=count+(ab[i]-mid)/b[i];
			if((ab[i]-mid)%b[i]>0)
			count++; 
			//cout<<mid<<" "<<ceil((ab[i]-mid)/((double)b[i]))<<"\n";
		}
	}
	//cout<<count<<"\n";
	
	return count;
}

int main()
{
	unsigned long long int n,m,ab[1000000],a[1000000],b[1000000],i,high=0,low=0,mid,ans=0,sum=0;
	cin>>n>>m;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		sum=sum+a[i];
	}
	for(i=0;i<n;i++)
		cin>>b[i];
	if(m>=sum)
	{
		cout<<"0";
		return 0;
	}
	for(i=0;i<n;i++)
	{
		ab[i]=a[i]*b[i];
		if(ab[i]>high)
			high=ab[i];
	}

	while(low<high)
	{
		mid=low+(high-low)/2;
		//cout<<mid<<"\n";
		if(count(mid,ab,a,b,n)<=m)
		{
			high=mid;
			ans=mid;
			//cout<<ans;
		}
		else
			low=mid+1;
	}
	cout<<ans;
	return 0;
}