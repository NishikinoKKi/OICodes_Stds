#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define lli long long int
using namespace std;
struct po
{
	long long int l,r,v;
}point[1000010];
long long int dp[2000010],que[2000010],tmp[2000010],dl,ql,tl,n,pl,mx,tp,at;
bool ag=0;
bool operator <(const po &a,const po &b)
{
	return a.r<b.r;
}
inline lli tmax(lli a,lli b,lli c)
{
	return max(max(a,b),c);
} 
int main()
{
	dl=ql=tl=0;
	pl=0;
	ql=1;
	scanf("%d",&n);
	for(register long long int i=1;i<=n;++i)
	{
		scanf("%d%d%d",&point[i].l,&point[i].r,&point[i].v);
		tmp[++tl]=point[i].l;
		tmp[++tl]=point[i].r;
	}
	sort(point+1,point+n+1);
	sort(tmp+1,tmp+tl+1);
	for(register long long int i=1;i<=tl;i++)
	{
		if(tmp[i]==tmp[i-1]) continue;
		que[++ql]=tmp[i];
	}
	que[0]=-1000;
	for(long long int i=1;i<=ql;i++)
	{
		if(que[i]==point[pl+1].r) {ag=1;++pl;}
		at=lower_bound(que+1,que+ql+1,point[pl].l)-que;
		dp[i]=tmax(dp[i-1],dp[i],dp[at]+point[pl].v);
		mx=max(mx,dp[i]);
		if(ag){ag=0;--i;}
	}	
	cout<<mx<<endl;
	return 0;
}
