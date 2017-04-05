#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int sum[110],f[110][110],w[110];
int n,tmp;
int main()
{
	scanf("%d",&n);
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&w[i]);
		sum[i]=sum[i-1]+w[i];
		f[i][i]=0;
	}
	for(int l=1;l<=n;l++)
	{
		for(int st=1;st<=n;st++)
		{
			int ed=st+l;
			for(int k=st;k<ed;k++)
			{
				f[st][ed]=min(f[st][ed],f[st][k]+f[k+1][ed]+sum[ed]-sum[st-1]);
			}
		}
	}
	printf("%d",f[1][n]);
	return 0;
}
