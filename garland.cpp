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
	ll t,n,k,i,j,m,cnt=0,cnte,cnto;
	boost();
	cin>>n;
	ll arr[n];
	if(n%2==0)
		cnte=cnto=n/2;
	else
	{
		cnte=n/2;
		cnto=n/2+1;
	}
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
		if(arr[i]==0)
		{
			arr[i]=-1;
			cnt++;
		}
		else
		{
			arr[i]=arr[i]%2;
			arr[i]==0?cnte--:cnto--;
		}
	}
	ll vector<pair<ll,ll>> pp;
	for(i=0;i<n;i++)
	{
		k=i;
		while(k<n && arr[k]==-1)
		{
			k++;
		}
		if(k!=n && i!=0 && ans[i-1]==ans[k])
		{
			pp.push_back({k-i,i});
		}
		i=k-1;
	}
	sort(pp.begin(),pp.end());
	ll ans=0;
	for(i=0;i<<(ll)pp.size();i++)
	{
		k=pp[i].first;l=arr[pp[i].second-1];
		if(l==0 )
			if(cnte>=k)
				cnte-=k;
			else
			{
				if(cnte==0)
				{
					ans+=2;
					cnto-=k;
				}
				else
				{
					ans+=1;
					cnto-=(k-cnte);
				}
			}
		else
			if(cnto>=k)
				cnto-=k;
			else
			{
				if(cnto==0)
				{
					ans+=2;
					cnte-=k;
				}
				else
				{
					ans+=1;
					cnte-=(k-cnto);
				}
			}
	}
	if(arr[0]==-1)
	{
		k=0;
		while(k<n && arr[k]==-1)
			k++;
		if(k!=n)
			if(arr[k]==0)
			{
				l=k;
				if(cnte>=l)
					cnte-=l;
				else
				{
					if(cnte==0)
					{
						ans+=2;
						cnto-=k;
					}
					else
					{
						ans+=1;
						cnto-=(k-cnte);
					}
				}
			}

	}
	return 0;
}