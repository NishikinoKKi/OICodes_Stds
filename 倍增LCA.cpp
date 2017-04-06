#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define debug cout
using namespace std;
const int maxn=1e4+1e2;
int p[maxn][36],deep[maxn],s[maxn],n,cnt;
bool rt[maxn];
struct node
{
	int to,nxt;
}map[maxn*2]; //*2 
inline void addedge(int &from,int &to)
{
	 map[++cnt].to=to;
	 map[cnt].nxt=s[from];
	 s[from]=cnt;
}
void dfs(int x)
{
	int at=s[x];
	while(at)
	{
		deep[map[at].to]=deep[x]+1;
		p[map[at].to][0]=x;
		dfs(map[at].to);
		at=map[at].nxt;
	}
}
inline void pre()
{
	for(int j=1;(1<<j)<=n;j++)
	{
		for(int i=1;i<=n;i++)
		{
				p[i][j]=p[p[i][j-1]][j-1];
		}
	}
}
inline int query(int a,int b)
{
	int i,j;
	if(deep[a]<deep[b]) swap(a,b);
	for(i=0;(1<<i)<=deep[a];i++);
	i--;
	for(int j=i;j>=0;j--)
	{
		if(deep[a]-(1<<j)>=deep[b])
		{
			a=p[a][j];
		}
	}
	if(a==b) return a;
	for(j=i;j>=0;j--)
	{
		if(p[a][j]&&p[a][j]!=p[b][j])
		{
			a=p[a][j];
			b=p[b][j];
		}
	}
	return p[a][0];
}
inline void init()
{
	memset(p,0,sizeof(p));
	memset(deep,0,sizeof(deep));
	memset(s,0,sizeof(s));
	memset(rt,0,sizeof(rt));
	memset(map,0,sizeof(map));
	n=cnt=0;
}
inline int findroot(int n)
{
	for(int i=1;i<=n;i++) if(!rt[i]) return i;
}
int main()
{
	int t,a,b,root;
	scanf("%d",&t);
	while(t--)
	{
		init();
		scanf("%d",&n);
		for(int i=1;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			addedge(a,b);
			rt[b]=1;
		}
		root=findroot(n);
		deep[root]=1;
		dfs(root);
		pre();
		scanf("%d%d",&a,&b);
		printf("%d\n",query(a,b));
	}
	return 0;
}
