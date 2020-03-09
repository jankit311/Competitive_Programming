#include<bits/stdc++.h>
using namespace std;
#define size 1000005
#define ll long long int

ll st[4*size],arr[size],Arr[size],copy_i[size];

void build(int in,int l,int r)
{
	if(l==r)
	{
		st[in]=0;
		return;
	}
	int m = l+(r-l)/2;
	build(2*in+1,l,m);
	build(2*in+2,m+1,r);
	st[in]=st[2*in+1]+st[2*in+2];
}

void update_point(int in,int l,int r,int val,int flag)
{
	if(l>r || val<l || r<val)
		return;
	if(l==r)
	{
		if(flag==0)
			st[in]=1;
		else
			st[in]=arr[val];
		return;
	}
	int m = l+(r-l)/2;
	if(val<=m)
		update_point(2*in+1,l,m,val,flag);
	else
		update_point(2*in+2,m+1,r,val,flag);
	st[in]=st[2*in+1]+st[2*in+2];
}

ll query_range(int in,int l,int r,int ql,int qr)
{
	if(l>r || ql>qr || qr<l || r<ql)
		return 0;
	if(ql<=l && qr>=r)
		return st[in];
	int m = l+(r-l)/2;
	ll res1 = query_range(2*in+1,l,m,ql,qr);
	ll res2 = query_range(2*in+2,m+1,r,ql,qr);
	return res1+res2;
}

int main()
{
	ll n,i,ans=0;

	scanf("%lld",&n);
	//cout<<"hi"<<n<<endl;
	arr[0]=0;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&arr[i]);
		copy_i[i]=arr[i];
	}
	//cout<<"hi"<<endl;
	sort(arr+1,arr+n+1);
	for(i=1;i<=n;i++)
	{
		Arr[i]=(lower_bound(arr+1,arr+n,copy_i[i])-arr);
	}
	for(i=n;i>=1;i--)
	{
		update_point(0,1,n,Arr[i],0);
		arr[Arr[i]]=query_range(0,1,n,1,Arr[i]-1);
	}
	build(0,1,n);
	//memset(st,0,4*n);
//	cout<<arr[1]<<endl;
	for(i=n;i>=1;i--)
	{
		update_point(0,1,n,Arr[i],1);
		ans+=query_range(0,1,n,1,Arr[i]-1);
		//cout<<arr[i]<<" "<<ans<<" "<<Arr[i]<<endl;
	}
	printf("%lld\n",ans);
	return 0;
}