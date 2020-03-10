#include <bits/stdc++.h>
using namespace std;
int t,n,m,p[10000007],i;
	long long int s=0;
int solve(long long int mid)
{
	long long int sum=0,req=1;
	for(i=0;i<n;i++)
	{
		sum+=p[i];
		if(sum>mid)
		{
			req++;
			sum=p[i];
		}
	}
	if(req<=m)
	return 1;
	else
	return 0;
}

int main() {
	int l,h,min,mid,sum;
	// your code goes here
	
	cin>>t;
	while(t--)
	{
		s=0;
		sum=0;
		min=10000007;
		cin>>n>>m;
		
		for(i=0;i<n;i++)
		{
			cin>>p[i];
			s=s+p[i];
			if(p[i]<min)
			min=p[i];
		}
		
		l=min;
		//cout<<s<<"\n";
		h=s;
		
		while(l<h)
		{
			mid=l+(h-l)/2;
			if(solve(mid))
			h=mid;
			else
			l=mid+1;
		}
		//cout<<l<<"\n";
		
		for(i=0;i<n;i++)
		{
			//cout<<"r"<<ceil(((double)s)/l)<<"\n";
			
			if(round(((double)s)/l)<m)
			{
				cout<<p[i]<<" "<<"/"<<" ";
				s=s-p[i];
				m--;
			}
			else
			{
			//cout<<"r"<<s<<"\n";
			sum+=p[i];
			if(sum<=l)
			{
			cout<<p[i]<<" ";
			}
			else
			if(sum>l)
			{
				cout<<"/"<<" "<<p[i]<<" ";
				sum=p[i];
			}
			}
		}
		cout<<"\n";
	}
	return 0;
}