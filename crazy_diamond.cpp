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

void swap(ll i,ll j,ll arr[],ll pos[])
{
	ll temp = arr[i];
	arr[i]=arr[j];
	arr[j]=temp;
	pos[arr[j]]=j;
	pos[arr[i]]=i;
}

int main()
{
    ll t,n,k,i,j;
    boost();
    cin>>n;
    ll arr[n+1];
    ll pos[n+1];
    for(i=1;i<=n;i++)
    {
    	cin>>arr[i];
    	pos[arr[i]]=i;
    }
    vector<pair<ll,ll> > ans;
    ans.clear();
    for(i=1;i<=n;i++)
    {
    	if(arr[i]!=i)
    	{
    		if(abs(pos[i]-i)>=(n/2))
    		{
    			ans.push_back({i,pos[i]});
    			swap(i,pos[i],arr,pos);
    		}
    		else
    		if((pos[i]-1)>=n/2 && (i-1)>=n/2)
    		{
    			j=pos[i];
    			swap(i,1,arr,pos);
    			ans.push_back({i,1});
    			swap(j,1,arr,pos);
    			ans.push_back({j,1});
    			swap(i,1,arr,pos);
    			ans.push_back({i,1});
    		}
    		else
    		if((n-pos[i])>=n/2 && (n-i)>=n/2)
    		{
    			j=pos[i];
    			swap(i,n,arr,pos);
    			ans.push_back({i,n});
    			swap(j,n,arr,pos);
    			ans.push_back({j,n});
    			swap(i,n,arr,pos);
    			ans.push_back({i,n});
    		}
    		else
    		{
    			j=pos[i];
    			swap(min(i,j),n,arr,pos);
    			ans.push_back({min(i,j),n});
    			swap(1,n,arr,pos);
    			ans.push_back({1,n});
    			swap(1,max(i,j),arr,pos);
    			ans.push_back({1,max(i,j)});
    			swap(1,n,arr,pos);
    			ans.push_back({1,n});
    			swap(min(i,j),n,arr,pos);
    			ans.push_back({min(i,j),n});
    		}
    	}
    }

    cout<<ans.size()<<endl;

    for(i=0;i<ans.size();i++)
    {
    	cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }

    return 0;
}