/**************************************************************
    Problem: 1013
    User: cmd2001
    Language: C++
    Result: Accepted
    Time:0 ms
    Memory:1292 kb
****************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define debug cout
using namespace std;
const double eps=1e-6;
double in[13][13],dat[13][13],num[13];
int n,ans[13];
bool used[13];
inline void debugp();
inline void prepare()
{
    double tmp=0;
    for(int i=1;i<=n;i++)
    {
        tmp=0;
        for(int j=1;j<=n;j++)
        {
            dat[i][j]=(in[i+1][j]-in[i][j])*2;
            tmp+=pow(in[i+1][j],2)-pow(in[i][j],2);
        }
        num[i]=tmp;
    }
}
inline void gauss()
{
    int x=0;
    double tmp;
    for(int i=1;i<=n;i++)//i代表正在消的元。
    {
        x=0;
        for(int j=1;j<=n;j++)
        {
            if(fabs(dat[j][i])>fabs(dat[x][i])&&!used[j]) x=j;
        }
        //debug<<x<<endl;
        if(x)
        {
            ans[i]=x;
            //printf("i==%d,x==%d\n",i,x);
            used[x]=1;
            for(int j=1;j<=n;j++)//j循环的是方程 
            {
                //printf("j==%d\n",j);
                if(j!=x&&fabs(dat[j][i])>0)
                {
                    tmp=-(dat[j][i]/dat[x][i]);
                    //debug<<"tmp=="<<tmp<<endl;
                    for(int k=1;k<=n;k++)//k为系数 
                    {
                        dat[j][k]+=tmp*dat[x][k];
                    }
                    num[j]+=tmp*num[x];
                }
            }
        }
        //debug<<"i=="<<i<<endl;
        //debugp();
    }
}
inline void output()
{
    int at;
    for(int i=1;i<n;i++)
    {
        at=ans[i];
        printf("%.3lf ",num[at]/dat[at][i]);
    }
    at=ans[n];
    printf("%.3lf",num[at]/dat[at][n]);
}
inline void debugp()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            debug<<dat[i][j]<<" ";
        }
        debug<<num[i];
        debug<<"\n";
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n+1;i++)
    {
        for(int j=1;j<=n;j++)
        {
            scanf("%lf",&in[i][j]);
        }
    }
    prepare();
    //debug<<"prepared"<<endl;
    //debugp(); 
    gauss();
    //debug<<"gaussed"<<endl;
    output();
    return 0;
}
