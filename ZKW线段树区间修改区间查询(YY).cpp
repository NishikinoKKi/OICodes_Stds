#include<bits/stdc++.h>
using namespace std;
const int maxn=200000+10;
long long int org[4*maxn],added[4*maxn];
int m,n,q;
long long int que(long long int* tree,int l,int r)
{
	long long int ret=0;
	for(l+=m-1,r+=m+1;l^r^1;l>>=1,r>>=1)//保证l,r不是只有最后一位不同，那种情况开区间无意义。 
	{
		if((~l)&1) ret+=tree[l^1];//如果左区间是左儿子，则右儿子应该加上。 
		if(r&1) ret+=tree[r^1];//如果右区间是右儿子，则左儿子应该加上。 
	}
	return ret;
}
void update(long long int* tree,int to,long long int v)
{
	for(tree[to+=m]+=v,to>>=1;to;to>>=1)//进行初始化。 
	{
		tree[to]=tree[(to<<1)]+tree[(to<<1)+1];//进行加法计算。 
	}
}
void build(long long int* tree)
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
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",org+m+i);
	}
	build(org);
	scanf("%d",&q);
	long long int x;
	for(int i=1,k,a,b;i<=q;i++)
	{
		scanf("%d",&k);
		if(k==1)
		{
			scanf("%d%d%lld",&a,&b,&x);
			update(added,a,x);
			update(added,b,-x);
			update(org,a,-(a-1)*x);
			update(org,b,b*x);
		}
		else if(k==2)
		{
			scanf("%d%d",&a,&b);
			long long int ans=0;
			ans=que(org,a,b)+que(added,1,b)*b-que(added,1,a-1)*(a-1);
			printf("%lld\n",ans);
		}
	}
	return 0;
}
