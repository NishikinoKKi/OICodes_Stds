#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define debug cout
using namespace std;
int dis[13000],to[13000],next[13000],fis[2550],vis[2550],ans[2550];
int t,c,s,e;
int mapl;
int main()
{
	memset(fis,0,sizeof(fis));
	scanf("%d%d%d%d",&t,&c,&s,&e);
	for(int i=1,rs,re,rc;i<=c;i++)
	{
		scanf("%d%d%d",&rs,&re,&rc);
		dis[++mapl]=rc;
		to[mapl]=re;
		next[mapl]=fis[rs];
		fis[rs]=mapl;
		dis[++mapl]=rc;
		to[mapl]=rs;
		next[mapl]=fis[re];
		fis[re]=mapl;
	}
	memset(ans,0x3f,sizeof(ans));
	ans[0]=0;ans[s]=0;
	for(int i=1,mi,at,x;i<=t;i++)
	{
		x=0x7fffffff;
		mi=0;
		for(int j=1;j<=t;j++)
		{
			if(x>ans[j]&&!vis[j]) {mi=j;x=ans[j];}
		}
		vis[mi]=1;
		at=fis[mi];
		while(at)
		{
			ans[to[at]]=min(ans[to[at]],ans[mi]+dis[at]);
			at=next[at];
		}
	}
	printf("%d",ans[e]);
	return 0;
}
