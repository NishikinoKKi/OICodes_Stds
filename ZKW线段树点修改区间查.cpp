#include<bits/stdc++.h>
using namespace std;
const int maxn=1048576;
int m,n,q;
int tree[maxn];
int que(int l,int r)
{
	int ret=0;
	for(l+=m-1,r+=m+1;l^r^1;l>>=1,r>>=1)//��֤l,r����ֻ�����һλ��ͬ��������������������塣 
	{
		if((~l)&1) ret+=tree[l^1];//���������������ӣ����Ҷ���Ӧ�ü��ϡ� 
		if(r&1) ret+=tree[r^1];//������������Ҷ��ӣ��������Ӧ�ü��ϡ� 
	}
	return ret;
}
void update(int to,int v)
{
	for(tree[to+=m]+=v,to>>=1;to;to>>=1)//���г�ʼ���� 
	{
		tree[to]=tree[(to<<1)]+tree[(to<<1)+1];//���мӷ����㡣 
	}
}
void build()
{
	for(int i=m-1;i>0;i--)
	{
		tree[i]=tree[i<<1]+tree[(i<<1)+1];
	}
}
void calcm(int x)
{
	int cnt=0;
	while(x>>=1) cnt++;//ͳ����ײ�ڵ������ 
	m=1<<(cnt+1);//��������m�� 
}
int main()
{
	scanf("%d",&n);
	calcm(n);
	for(int i=1;i<=n;i++) scanf("%d",tree+m+i);
	build();
	scanf("%d",&q);
	for(int i=1,k,a,b;i<=q;i++)
	{
		scanf("%d%d%d",&k,&a,&b);
		if(k==1) update(a,b);
		else printf("%d\n",que(a,b));
	}
	return 0;
}
