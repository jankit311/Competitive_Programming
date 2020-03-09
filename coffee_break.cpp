#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mod = 1e9+7;
ll ans[200002];

ll upper(vector<pair<ll,ll> > a,int k,int l)
{
	int h=a.size()-1,res=a.size(),m;
	while(l<=h)
	{
		m=l+(h-l)/2;
		if(a[m].first<=k)
			l=m+1;
		else
		{
			if(ans[a[m].second]!=0)
				l=m+1;
			else
			{
				res=min(res,m);
				h=m-1;
			}
		}
	}
	return res;
}

void boost()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int main()
{
	ll m,n,d,i,x;
	boost();
	cin>>n>>m>>d;
	vector<pair<ll,ll> > a;
	//fill(ans,ans+n,-1);
	for(i=0;i<n;i++)
	{
		cin>>x;
		a.push_back({x,i});
	}
	sort(a.begin(),a.end());
	ll day=0,temp,c=1;
	for(i=0;i<a.size();i++)
	{
		if(ans[a[i].second]==0)
		{
			day++;
			ans[a[i].second]=day;
		}
		temp = upper(a,a[i].first+d,c);
		c=max(c,temp+1);
		if(temp<a.size())
			ans[a[temp].second]=ans[a[i].second];
	}
	cout<<day<<endl;
	for(i=0;i<n;i++)
		cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}