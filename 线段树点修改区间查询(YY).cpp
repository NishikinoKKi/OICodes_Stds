#include<iostream>
#include<cstdio>
#include<cstring>
#define debug cout
using namespace std;
struct tre
{
	int l,r,sum;
}tree[2000010];
int num[100010],n2t[100010];
int n,m;
int old;
int buildt(int l,int r,int pos)
{
	if(r>n||l>r) return 0;
	if(l==r)
	{
		tree[pos].l=tree[pos].r=l;
		tree[pos].sum=num[l];
		n2t[l]=pos;
		return tree[pos].sum;
	}
	else
	{
		int mid=(r+l)/2;
		tree[pos].l=l;
		tree[pos].r=r;
		tree[pos].sum=buildt(l,mid,2*pos)+buildt(mid+1,r,2*pos+1);
		return tree[pos].sum;
	}
}
void change(int pos,int plus)
{
	if(pos)
	{
		tree[pos].sum+=plus;
		change(pos/2,plus);
	}
}
int retsum(int l,int r,int pos)
{
	if(l==tree[pos].l&&r==tree[pos].r) return tree[pos].sum;
	else
	{
		int mid=(tree[pos].l+tree[pos].r)/2;
		if(r<mid+1) return retsum(l,r,pos*2);
		else if(l>mid) return retsum(l,r,pos*2+1);
		else
		{
			return retsum(l,mid,pos*2)+retsum(mid+1,r,pos*2+1);
		}
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&num[i]);
	}
	buildt(1,n,1);
	scanf("%d",&m);
	for(int i=1,q,a,b;i<=m;i++)
	{
		scanf("%d%d%d",&q,&a,&b);
		if(q==1)
		{
			num[a]+=b;
			change(n2t[a],b);
		}
		else if(q==2)
		{
			printf("%d\n",retsum(a,b,1));
		}
	}
	return 0;
}
