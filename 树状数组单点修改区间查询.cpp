#include<bits/stdc++.h>
#define lowerbit(x) (x&-x)
using namespace std;
int n;
int sum[100100];
void update(int to,int x)
{
	while(to<=n)
	{
		sum[to]+=x;
		to+=lowerbit(to);
	}
}
int read(int from)
{
	int ret=0;
	while(from)
	{
		ret+=sum[from];
		from-=lowerbit(from);
	}
	return ret;
}
int main()
{
	scanf("%d",&n);
	for(int i=1,tmp;i<=n;i++)
	{
		scanf("%d",&tmp);
		update(i,tmp);
	}
	int m;
	scanf("%d",&m);
	for(int i=1,q,a,b;i<=m;i++)
	{
		scanf("%d",&q);
		if(q==1)
		{
			scanf("%d%d",&a,&b);
			update(a,b);
		}
		else if(q==2)
		{
			scanf("%d%d",&a,&b);
			printf("%d\n",read(b)-read(a-1));
		}
	}
	return 0;
}
