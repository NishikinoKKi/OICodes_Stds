#include<cstdio>
#include<algorithm>
using namespace std;
int in[5010],que[5010],ql,n,at;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&in[i]);
	ql=0;
	que[0]=-32767;
	for(int i=1;i<=n;i++)
	{
		at=lower_bound(que,que+ql+1,in[i])-que;
		if(at>ql) ql++;
		que[at]=in[i];
	}
	printf("%d",ql);
	return 0;
}
