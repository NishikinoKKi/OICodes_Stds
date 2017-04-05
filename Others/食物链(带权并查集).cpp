#include<iostream>
#include<cstdio>
#include<cstring>
#define debug cout
using namespace std;
struct nod
{
	int bro,r;
}node[50050];
int n,k,x,y,d,ans,tx,ty,del;
int find(int x)
{	
	if(x==node[x].bro) return x;
	else
	{
		int tmp=node[x].bro;
		node[x].bro=find(node[x].bro);
		node[x].r=(node[x].r+node[tmp].r)%3;
		return node[x].bro;
	}
}
int main()
{
	for(int i=1;i<=50000;i++) {node[i].bro=i;node[i].r=0;}
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++)
	{
		scanf("%d%d%d",&d,&x,&y);
		if(x>n||y>n) {++ans;continue;}
		else
		{
			tx=find(x);
			ty=find(y);
			if(d==1)
			{
				if(tx==ty) 
				{
					if(node[x].r==node[y].r) continue;
					else ++ans;
				}
				else
				{
					node[ty].bro=tx;
					node[ty].r=(node[x].r-node[y].r+3)%3;
				}
			}
			else if(d==2)
			{
				if(tx==ty)
				{
					if((node[x].r+1)%3==node[y].r) continue;
					else ++ans;
				}
				else
				{
					node[ty].bro=tx;
					node[ty].r=(node[x].r-node[y].r+4)%3;
				}
			}
		}
	}
	printf("%d",ans);
	return 0;
}
