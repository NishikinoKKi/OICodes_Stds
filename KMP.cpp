#include<bits/stdc++.h> 
using namespace std;
char T[110],P[110];
int f[110];
void getFail(char *P,int *f)
{
	int n=strlen(P);
	f[0]=f[1]=0;
	for(int i=1;i<n;i++)
	{
		int j=f[i];
		while(j&&P[i]!=P[j]) j=f[j];
		f[i+1]=(P[j]==P[i]?j+1:0);
	}
}
void kmp(char *T,char *P,int *f)
{
	int m=strlen(T),n=strlen(P);
	getFail(P,f);
	int j=0;
	for(int i=0;i<m;i++)
	{
		while(j&&T[i]!=P[j]) j=f[j];
		if(T[i]==P[j]) j++;
		if(j==n)
		{
			printf("%d\n",i-j+2);
			return;
		}
	}
}
int main()
{
	scanf("%s",T);
	scanf("%s",P);
	kmp(T,P,f);
	return 0;
}
