#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct per
{
	int iq,eq;
}person[1010];
bool operator < (const per &a,const per &b)
{
	return a.iq==b.iq?a.eq<b.eq:a.iq<b.iq;
}
int n,dp[1010],tmp;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d",&person[i].iq,&person[i].eq);
	sort(person+1,person+1+n);
	for(int i=1;i<=n;i++)
	{
		dp[i]=1;
		for(int j=1;j<i;j++)
		{
			if(person[j].eq<=person[i].eq) dp[i]=max(dp[i],dp[j]+1);
		}
		tmp=max(tmp,dp[i]);
	}
	printf("%d",tmp);
	return 0;
}
