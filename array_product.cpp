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
	ll t,n,k,i,j,m,cn=0,cz=0;
	boost();
	cin>>n;
	vector<pair<ll,ll>> arr(n),ans,;
	for(i=0;i<n;i++)
	{
		cin>>arr[i].first;
		arr[i].second=i+1;
		if(arr[i].first<0)
				cn++;
		if(arr[i].first==0)
				cz++;
	}

	sort(arr.begin(),arr.end());

	if(cn%2 && cz>0)
	{
		if(cn==1 && cz==(n-1))
		{
			for(i=0;i<n-1;i++)
				ans.push_back({arr[i].second,arr[i+1].second});
		}
		else
		{
			for(i=0;i<n-1;i++)
			{
				if(arr[i]==0)
					ans.push_back()
			}
		}
	}



	return 0;
}