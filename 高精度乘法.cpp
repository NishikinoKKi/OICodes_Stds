#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int c[2000];
struct HIGHINT
{
    string in;
    int number[1000];
};
void i2n(HIGHINT &i)
{
    i.number[0]=i.in.length();
    for(int j=1;j<=i.number[0];j++)
    {
        i.number[j]=i.in[i.number[0]-j]-'0';
    }
}
void ope_x(HIGHINT a,HIGHINT b,int cl)
{
    for(int i=1;i<=a.number[0];i++)
    {
        for(int j=1;j<=b.number[0];j++)
        {
            c[i+j-1]+=a.number[i]*b.number[j];
            c[i+j]+=c[i+j-1]/10;
            c[i+j-1]%=10;
        }
    }
    for(int i=1;i<=cl;i++)
    {
        c[i+1]+=c[i]/10;
        c[i]%=10;
    }
}
int cutzero(int cl)
{
    int i,j;
    for(i=1;i<=cl;i++)
    {
        if(c[i]!=0) j=i;
    }
    return j;
}
void out(int l)
{
    for(int i=c[0];i>0;i--) {cout<<c[i];}
}
int main()
{
    HIGHINT a,b;
    memset(c,0,sizeof(c));
    cin>>a.in>>b.in;
    i2n(a);
    i2n(b);
    if(a.in=="0"||b.in=="0") {cout<<"0"<<endl; return 0;}
    ope_x(a,b,2000);
    c[0]=cutzero(2000);
    out(2000);
    return 0;
}
