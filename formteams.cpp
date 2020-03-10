#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,arr[101],ans=0;

	cin>>n;

	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}

	sort(arr,arr+n);

	for(int i=0;i<n-1;i+=2)
	{
		ans+=arr[i+1]-arr[i];
	}

	cout<<ans<<endl;
	return 0;
}