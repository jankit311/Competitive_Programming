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
	ll t,n,k,i,m;
	boost();
	cin>>n;
	vector<pair<ll,ll> > v;
	ll c=0,r=1,j,a=1,b=1,mr=1;
	ll arr[100005];
	//memset(arr,1,sizeof(arr));
	for(i=1;i<=100000;i++)
		arr[i]=1;
	//cout<<arr[1]<<endl;
	while(1)
	{
		//cout<<c<<n<<endl;
		if(c==n)
			break;
		r=mr;
		//cout<<r<<mr<<c<<endl;
		for(i=1;i<=r;i++)
		{
			for(j=arr[i];j<=r;j++)
			{
				//cout<<i<<j<<c<<endl;
				if(((i-1)+(j-1))>=c)
				{
					v.push_back({i,j});
					c++;
					arr[i]=j+1;
				}
				if(c==n)
					break;
				if(i==r && j==r && c<n)
					mr=mr+1;
			}
			if(c==n)
				break;
		}
	}
	cout<<mr<<endl;
	for(i=0;i<v.size();i++)
		cout<<v[i].first<<" "<<v[i].second<<endl;
	return 0;
}