#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define lson (pos<<1)
#define rson ((pos<<1)|1)
#define mid (tree[pos].l+tree[pos].r)/2
#define debug cout
#define debugf printf
struct node
{
	long long int l,r,sum,add,update;
}tree[4194304];
long long int num[200010],m,n;
long long int buildt(long long int l,long long int r,long long int pos)
{
	if(r>n||l>r) return 0;
	if(l==r)
	{
		tree[pos].l=tree[pos].r=l;
		tree[pos].sum=num[l];
		return tree[pos].sum;
	}
	else
	{
		tree[pos].l=l;
		tree[pos].r=r;
		tree[pos].sum=buildt(l,mid,2*pos)+buildt(mid+1,r,2*pos+1);
		return tree[pos].sum;
	}
}
void tplus(long long int l,long long int r,long long int x,long long int pos)
{
	tree[pos].update+=(r-l+1)*x;
	if(l==tree[pos].l&&r==tree[pos].r) {tree[pos].add+=x;return;}
	if(r<mid) {tplus(l,r,x,lson);return;}
	if(l>mid) {tplus(l,r,x,rson);return;}
	if(l<=mid) tplus(l,mid,x,lson);
	if(r>mid) tplus(mid+1,r,x,rson);
}
long long int retsum(long long int l,long long int r,long long int pos)
{
	//debugf("addfx==%d\n",tree[pos].add*(r-l+1));
	if(l==tree[pos].l&&r==tree[pos].r) {return tree[pos].sum+tree[pos].update;}
	else
	{
		if(r<mid+1) return retsum(l,r,pos*2)+tree[pos].add*(r-l+1);
		else if(l>mid) return retsum(l,r,pos*2+1)+tree[pos].add*(r-l+1);
		else
		{
			return retsum(l,mid,pos*2)+retsum(mid+1,r,pos*2+1)+tree[pos].add*(r-l+1);
		}
	}
}
int main()
{
	scanf("%lld",&n);
	for(long long int i=1;i<=n;i++) scanf("%lld",&num[i]);
	buildt(1,n,1);
	scanf("%lld",&m);
	for(long long int i=1,q,a,b,x;i<=m;i++)
	{
		scanf("%lld",&q);
		if(q==1)
		{
			scanf("%lld%lld%lld",&a,&b,&x);
			tplus(a,b,x,1);
		}
		else if(q==2)
		{
			scanf("%lld%lld",&a,&b);
			printf("%lld\n",retsum(a,b,1));
		}
	}
	return 0;
}
