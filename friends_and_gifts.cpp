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
	ll t,n,k,i,j,m;
	boost();
	cin>>n;
	ll arr[n],in[n],out[n];
	for(i=0;i<n;i++)
	    in[i]=out[i]=0;
	vector<ll> p,q,loop;
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
		arr[i]--;
		if(arr[i]!=-1)
		{
		    in[arr[i]]++;
		    out[i]++;
		}
	}

	for(i=0;i<n;i++)
		if(in[i]==0 && out[i]==0)
			loop.push_back(i);
	//cout<<loop[0]<<endl;
	if(loop.size()==1)
	{
		k=loop[0];
		for(i=0;i<n;i++)
		{
			if(in[i]==0 && k!=i)
			{
				arr[k]=i;
				in[i]++;
				out[k]++;
				break;
			}
		}
	}
	else
	if(loop.size()>1)
	{
		for(i=0;i<(int)loop.size();i++)
		{
			j=loop[i];
			k=loop[(i+1)%((int)loop.size())];
			arr[j]=k;
			in[k]++;
			out[j]++;
		}
	}
    /*for(i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;*/	

	for(i=0;i<n;i++)
	{
		if(in[i]==0)
			p.push_back(i);
		if(out[i]==0)
			q.push_back(i);
	}
	if(q.size()==p.size())
		for(i=0;i<(int)q.size();i++)
			arr[q[i]]=p[i];
	for(i=0;i<n;i++)
		cout<<arr[i]+1<<" ";
	cout<<endl;
	return 0;
}