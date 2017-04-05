#include<iostream>
#include<cstdio>
#include<cstring>
#define debug cout
using namespace std;
int tx,ty,n,sx,sy;//x为行，y为列。 
char cha[55][55],com[10];
int map[55][55];
int que[2][2600][2],ql[2];
int dx[]={0,-1,+1,0,0},dy[]={0,0,0,-1,+1};
bool vis[55][55];
void core_search(int x,int y,int to,int i);
int pd()
{
	switch(com[0])
	{
		case'N':{return 1;break;}
		case'S':{return 2;break;}
		case'W':{return 3;break;}
		case'E':{return 4;break;}
	}
}
void search(int toward,int tme)
{
	memset(vis,0,sizeof(vis));
	int from=(tme-1)%2,to=tme%2; 
	ql[to]=0;
	for(int i=1;i<=ql[from];i++)
	{
		core_search(que[from][i][0],que[from][i][1],toward,to);
	}
}
void core_search(int x,int y,int to,int i)
{
	x+=dx[to];y+=dy[to];
	while(x<=tx&&x>0&&y<=ty&&y>0&&!map[x][y]&&!vis[x][y])
	{
		vis[x][y]=1;
		que[i][++ql[i]][0]=x;
		que[i][ql[i]][1]=y;
		x+=dx[to];y+=dy[to];
	}
}
int main()
{
	int last;
	scanf("%d%d",&tx,&ty);
	for(int i=1;i<=tx;i++)
	{
		scanf("%s",cha[i]+1);
	}
	for(int i=1;i<=tx;i++)
	{
		for(int j=1;j<=ty;j++)
		{
			if(cha[i][j]=='X') map[i][j]=1;
			else if(cha[i][j]=='*') {sx=i;sy=j;}
		}
	}
	ql[0]=1;
	que[0][1][0]=sx;que[0][1][1]=sy;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",com);
		search(pd(),i);
	}
	last=n%2;
	cha[sx][sy]='.';
	for(int i=1;i<=ql[last];i++)
	{
		cha[que[last][i][0]][que[last][i][1]]='*';
	}
	for(int i=1;i<=tx;i++)
	{
		for(int j=1;j<=ty;j++)
		{
			printf("%c",cha[i][j]);
		}
		printf("\n");
	}
	return 0;
}	
