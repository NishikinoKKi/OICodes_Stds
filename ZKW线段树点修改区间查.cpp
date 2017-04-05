#include<bits/stdc++.h>
using namespace std;
const int maxn=1048576;
int m,n,q;
int tree[maxn];
int que(int l,int r)
{
	int ret=0;
	for(l+=m-1,r+=m+1;l^r^1;l>>=1,r>>=1)//保证l,r不是只有最后一位不同，那种情况开区间无意义。 
	{
		if((~l)&1) ret+=tree[l^1];//如果左区间是左儿子，则右儿子应该加上。 
		if(r&1) ret+=tree[r^1];//如果右区间是右儿子，则左儿子应该加上。 
	}
	return ret;
}
void update(int to,int v)
{
	for(tree[to+=m]+=v,to>>=1;to;to>>=1)//进行初始化。 
	{
		tree[to]=tree[(to<<1)]+tree[(to<<1)+1];//进行加法计算。 
	}
}
void build()
{
	for(int i=m-1;i>0;i--)
	{
		tree[i]=tree[i<<1]+tree[(i<<1)+1];
	}
}
void calcm(int x)
{
	int cnt=0;
	while(x>>=1) cnt++;//统计最底层节点个数。 
	m=1<<(cnt+1);//暴力计算m。 
}
int main()
{
	scanf("%d",&n);
	calcm(n);
	for(int i=1;i<=n;i++) scanf("%d",tree+m+i);
	build();
	scanf("%d",&q);
	for(int i=1,k,a,b;i<=q;i++)
	{
		scanf("%d%d%d",&k,&a,&b);
		if(k==1) update(a,b);
		else printf("%d\n",que(a,b));
	}
	return 0;
}
