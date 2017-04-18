#include<bits/stdc++.h>
#define debug cout
using namespace std;
const int maxn=1e3+1e2;
int in[maxn],a[maxn],b[maxn],ad,bd,k,n,cnt,asd;
char ans[2*maxn];
bool check(int k)
{
    if(!bd) return 1;
    int i,j;
    for(i=k+1;i<=n;i++) if(in[i]>in[k]&&in[i]>b[bd]) break;
    for(j=i+1;j<=n;j++) if(in[j]<in[k]) return 0;
    return 1;
}
bool dfs(int at)
{
    if(asd>n) return 1;
    if(a[ad]==asd)
    {
        ad--,asd++;
        ans[++cnt]='b';
        return dfs(at);
    }
    if(b[bd]==asd)
    {
        bd--,asd++;
        ans[++cnt]='d';
        return dfs(at);
    }
    if(at<=n&&in[at]<a[ad]&&check(at))
    {
        a[++ad]=in[at];
        ans[++cnt]='a';
        return dfs(at+1);
    }
    if(at<=n&&in[at]<b[bd])
    {
        b[++bd]=in[at];
        ans[++cnt]='c';
        return dfs(at+1);
    }
    return 0;
}

int main()
{
    scanf("%d",&n);
    a[0]=b[0]=1e4,asd=1;
    for(int i=1;i<=n;i++) scanf("%d",in+i);
    if(dfs(1)) for(int i=1;i<=cnt;i++) putchar(ans[i]),putchar(' ');
    else putchar('0');
    putchar('\n');
    return 0;
}
/*
bool check(int k)
{
    if(!bd) return 1;
    int x,j;
    for(x=k+1;x<=n;x++) if(in[x]>in[k]&&in[x]>b[bd]) break;
    for(j=x+1;j<=n;j++) if(in[j]<in[k]) return 0;
    return 1;
}

�����ڼ���k��Ԫ���ܷ����aջ��
�����÷�֤�����������ܽ���aջ��
�������ǿ��ǣ�������aջ���Ƿ����ì�ܡ�
���ȣ��ҵ��������һ��������(�������������aջ)�����Ҵ���bջջ����Ԫ��x����������ֶ�������ô���x������k����ǰ��ջ��
���ǣ����k�����x���Խ�ջǰ�������˵Ļ���x���ǿ��Խ�ջ�ġ�
���ԣ����Ǵ�x+1��ʼѰ���Ƿ���С��k��Ԫ�أ�����Ҳ�������k����ڳ��Խ�ջxǰ�������ˡ�
��ôx�����н⡣
��k���Խ���aջ��

���⣬���k���ܽ���aջ�Ļ����ͱ������bջ�����ԣ������ȵ�������a����b��˳����г��ԣ��ǲ���Ҫ���ݵģ�
��ʱ�临�Ӷ�O(n*n)����1000���������´����ࡣ
*/

