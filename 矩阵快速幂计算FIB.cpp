#include<bits/stdc++.h>
const long long int mod=1000000007;
using namespace std;
struct matex
{
	long long int m[5][5];
}base,org,ans;
void multi(const matex a,const matex b,matex &to)
{
	for(int i=1;i<=2;i++)
	{
		for(int j=1;j<=2;j++)
		{
			to.m[i][j]=0;
			for(int k=1;k<=2;k++)
			{
				to.m[i][j]+=(a.m[i][k]*b.m[k][j])%mod;
			}
		}
	}
}
void fastpow(long long int x)
{
	ans=org;
	matex tmp=base;
	while(x)
	{
		if(x&1) multi(tmp,ans,ans);
		multi(tmp,tmp,tmp);
		x>>=1;
	}
}
int main()
{
	base.m[1][1]=base.m[1][2]=base.m[2][1]=1;
	org.m[1][1]=org.m[2][1]=1;
	long long int x;
	while(scanf("%lld",&x)==1)
	{
		if(x==1||x==2) {printf("1\n");continue;}
		fastpow(x-2);
		printf("%lld\n",ans.m[1][1]%mod);
	}
	return 0;
}
