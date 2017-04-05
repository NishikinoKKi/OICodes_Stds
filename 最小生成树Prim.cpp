#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define debug cout
using namespace std;
int len[110][110];
int vis[110];
int n,ans;
int main()
{
	ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&len[i][j]);
		}
	}
	int i,j,t,mi,mix,miy;
	vis[1]=1;
	for(i=1;i<n;i++)
	{
		mi=0x7f7f7f7f;
		for(j=1;j<=n;j++)
		{
			if(vis[j])
				for(t=1;t<=n;t++)
				{
					if(mi>len[j][t]&&!vis[t])
					{
						mi=len[j][t];
						mix=j;
						miy=t;
					}
				}
		}
		ans+=len[mix][miy];
		vis[miy]=1;	
	}
	printf("%d",ans);
	return 0;
}
