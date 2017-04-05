#include<bits/stdc++.h>
#define debug cout
using namespace std;
struct matex
{
	double m[5][5];
}base,org,ans,out;
int n,f0,f1;
double a,b;
long long int myround(double r)
{
	return r>0.0?floor(r+0.5):ceil(r-0.5);
}
void multi(const matex a,const matex b,matex &to)
{
	for(int i=1;i<=2;i++)
	{
		for(int j=1;j<=2;j++)
		{
			to.m[i][j]=0;
			for(int k=1;k<=2;k++)
			{
				to.m[i][j]+=a.m[i][k]*b.m[k][j];
			}
		}
	}
}
void output(const matex &a)
{
	for(int i=1;i<=2;i++)
	{
		for(int j=1;j<=2;j++) printf("%.4lf ",a.m[i][j]);
		printf("\n");
	}
}
void fastpow(int x)
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
	scanf("%d%d%lf%lf%d",&f0,&f1,&a,&b,&n);
	if((f0==f1)&&!f0) {printf("%d\n",f0);return 0;}
	if(n==0) {printf("%d\n",f0);return 0;}
	if(n==1) {printf("%d\n",f1);return 0;}
	base.m[1][1]=a;
	base.m[1][2]=b;
	base.m[2][1]=1;
	base.m[2][2]=0;
	org.m[1][1]=f1;
	org.m[2][1]=f0;	
	fastpow(n-1);
	printf("%lld\n",myround(ans.m[1][1]));
	return 0;
}
/*
�������¶����ڷǸ�����n�ϵĵݹ��ϵ

f(n) = f0 (if n = 0)

       = f1 (if n = 1)

       = a*f(n-1)+b*f(n-2)  otherwise

����a,b�������������������ĳ�����

(1) a2+4b>0

(2) |a-sqrt(a2+4b)| <= 2   // sqrt�Ǹ��ŵ���˼

����f0,f1, a, b��n������дһ���������fn�����Լٶ�fn�Ǿ���ֵ������109������(��������)��

����������1��

0 1 1 1 20

����������2��

0 1 -1 0 1000000000

����������3��

-1 1 4 -3 18 

���������1��

6765

���������2��

-1

���������3��

387420487
*/
