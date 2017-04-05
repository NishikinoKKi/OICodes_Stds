#include<iostream>
#include<cstdio>
using namespace std;
void pri(int x,int a,int b)
{
	printf("%d from %c to %c\n",x,a+'A'-1,b+'A'-1);
}
void move(int x,int from,int to,int by)
{
	if(x==1) pri(x,from,to);
	else
	{
		move(x-1,from,by,to);
		pri(x,from,to);
		move(x-1,by,to,from);
	}
}
int main()
{
	int n,sum;
	cin>>n;
	sum=2;
	for(int i=1;i<n;i++) sum*=2;
	cout<<sum-1<<endl;
	move(n,1,3,2);
	return 0;
}
