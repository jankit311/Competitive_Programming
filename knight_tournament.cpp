#include<bits/stdc++.h>
using namespace std;
#define size 300005
struct node
{
	bool v;
	int res;
};

int arr[size];
struct node st[4*size];

void build(int in,int l,int r)
{
	if(l==r)
	{
		st[in].res=0;
		arr[l]=0;
		st[in].v=false;
		return;
	}

	int m = l+(r-l)/2;
	build(2*in+1,l,m);
	build(2*in+2,m+1,r);
	st[in].res=0;
	st[in].v = (st[2*in+1].v && st[2*in+2].v)?true:false;
}

void update_range(int in,int l,int r,int ql,int qr,int x)
{
	int m;
	if(l>r | l>qr | r<ql)
		return;
	if(st[in].v)
		return;
	if(ql<=l && r<=qr)
	{
		if(l==r)
		{
			if(l==x)
				return;
			st[in].v=true;
			st[in].res=x;
			arr[l]=x;
			return;
		}
		else
		{
			m = l+(r-l)/2;
			update_range(2*in+1,l,m,ql,qr,x);
			update_range(2*in+2,m+1,r,ql,qr,x);
			st[in].v = (st[2*in+1].v && st[2*in+2].v)?true:false;
			st[in].res=x;
			return;
		}
	}
	m = l+(r-l)/2;
	update_range(2*in+1,l,m,ql,qr,x);
	update_range(2*in+2,m+1,r,ql,qr,x);
	st[in].v = (st[2*in+1].v && st[2*in+2].v)?true:false;
	st[in].res=x;
}

int main()
{
	int n,m,i,ql,qr,x;
	scanf("%d %d",&n,&m);
	build(0,1,n);
	for(i=0;i<m;i++)
	{
		scanf("%d %d %d",&ql,&qr,&x);
		update_range(0,1,n,ql,qr,x);
	}
	for(i=1;i<=n;i++)
		printf("%d ",arr[i]);
	return 0;
}