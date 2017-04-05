#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1e6+100;
int fa[maxn],son[maxn],s[maxn],siz[maxn],top[maxn],dep[maxn];
struct edge
{
	int to,nxt;
}map[maxn];
int n,cnt;
void addedge(int from,int to)
{
	int tmp=s[from];
	s[from]=++cnt;
	map[cnt].to=to;
	map[cnt].nxt=tmp;
}
void pre(int x)
{
	siz[x]=1;
	int at=s[x];
	while(at)
	{
		fa[map[at].to]=x;
		dep[map[at].to]=dep[x]+1;
		pre(map[at].to);
		siz[x]+=siz[map[at].to];
		if(siz[map[at].to]>siz[son[x]]) son[x]=map[at].to;
		at=map[at].nxt;
	}
}
void dfs(int x)
{
	if(x==son[fa[x]]) top[x]=top[fa[x]];
	else top[x]=x;
	int at=s[x];
	while(at)
	{
		dfs(map[at].to);
		at=map[at].nxt;
	}
}
int query(int x,int y)
{
	while(top[x]!=top[y])
	{
		if(dep[x]>dep[y]) x=fa[top[x]];
		else y=fa[top[y]];
	}
	return dep[x]<dep[y]?x:y;
}
		
int main()
{
	dep[1]=1;
	int a,b;
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		addedge(a,b);
	}
	pre(1);
	dfs(1);
	scanf("%d%d",&a,&b);
	printf("%d\n",query(a,b));
	return 0;
}
