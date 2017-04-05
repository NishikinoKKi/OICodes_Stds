#include<iostream>
#include<cstdio>
#include<cstring>
#define debug cout
using namespace std;
int heap[5000050],n,at,tmp;
inline void swp(int &a,int &b)
{
	int c=a;
	a=b;
	b=c;
}
int findmin(int a,int b)
{
	if(heap[a]>heap[b]) return b;
	else return a;
}
void Heap_Fix(int from)
{
	if(!from||from==1) return;
	if(heap[from]<heap[from/2]) {swp(heap[from],heap[from/2]);Heap_Fix(from/2);}
}
void Heap_Insert(int in,int to)
{
	heap[to]=in;
	Heap_Fix(to);
}
void Heap_Fix_Down(int from)
{
	if(from*2>at&&from*2+1>at) return;
	if(from*2<=at&&from*2+1>at)
	{
		if(heap[from]>heap[from*2]){swp(heap[from],heap[from*2]); Heap_Fix_Down(from*2);}
	}
	else if(from*2<=at&&from*2+1<=at)
	{
		int to=findmin(from*2,from*2+1);
		if(heap[from]>heap[to]){swp(heap[from],heap[to]); Heap_Fix_Down(to);}
	}
}
int Heap_Pop()
{
	tmp=heap[1];
	heap[1]=heap[at];
	--at;
	Heap_Fix_Down(1);
	return tmp;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&tmp);
		Heap_Insert(tmp,++at);
	}
	for(int i=1;i<=n;i++)
	{
		printf("%d ",Heap_Pop());
	}
	return 0;
}
