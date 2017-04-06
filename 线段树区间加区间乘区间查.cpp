#include<bits/stdc++.h>
#define lson (p<<1)
#define rson ((p<<1)|1)
#define mid (l[p]+r[p])/2
#define LL long long
#define int long long
#define debug cout
using namespace std;
const int maxn=300000,mod=1000000007;
int n,m;
int l[maxn<<2],r[maxn<<2],mul[maxn<<2],sum[maxn<<2],add[maxn<<2];
int in[maxn+10];
void build(int p,int ll,int rr)
{
    l[p]=ll;r[p]=rr;
    mul[p]=1;
    if(ll==rr)
    {
        sum[p]=in[ll];
    }
    else
    {
        build(lson,ll,mid);
        build(rson,mid+1,rr);
        sum[p]=((LL)sum[lson]+sum[rson])%mod;
    }
}
void down(int p)
{
    if(mul[p]!=1)
    {
        mul[lson]=(LL)mul[lson]*mul[p]%mod;
        mul[rson]=(LL)mul[rson]*mul[p]%mod;
        sum[lson]=(LL)sum[lson]*mul[p]%mod;
        sum[rson]=(LL)sum[rson]*mul[p]%mod;
        add[lson]=(LL)add[lson]*mul[p]%mod;
        add[rson]=(LL)add[rson]*mul[p]%mod;
        mul[p]=1;
    }
    if(add[p])
    {
        add[lson]=((LL)add[lson]+add[p])%mod;
        add[rson]=((LL)add[rson]+add[p])%mod;
        sum[lson]=((LL)sum[lson]+add[p]*(r[lson]-l[lson]+1))%mod;
        sum[rson]=((LL)sum[rson]+add[p]*(r[rson]-l[rson]+1))%mod;
        add[p]=0;
    }
}
void tplus(int p,int ll,int rr,int x)
{
    if(ll<=l[p]&&rr>=r[p])
    {
        add[p]=((LL)add[p]+x)%mod;
        sum[p]=((LL)x*(r[p]-l[p]+1)+sum[p])%mod;
        return;
    }
    down(p);
    if(ll<=mid) tplus(lson,ll,rr,x);
    if(rr>mid) tplus(rson,ll,rr,x);
    sum[p]=((LL)sum[lson]+sum[rson])%mod;
}
void multi(int p,int ll,int rr,int x)
{
    if(ll<=l[p]&&rr>=r[p])
    {
        mul[p]=((LL)mul[p]*x)%mod;
        sum[p]=(LL)sum[p]*x%mod;
        add[p]=(LL)add[p]*x%mod;
        return;
    }
    down(p);
    if(ll<=mid) multi(lson,ll,rr,x);
    if(rr>mid) multi(rson,ll,rr,x);
    sum[p]=((LL)sum[lson]+sum[rson])%mod;
}
int read(int p,int ll,int rr)
{
    if(rr<l[p]||ll>r[p]) return 0;
    else if(ll<=l[p]&&rr>=r[p]) return sum[p];
    down(p);
    return ((LL)read(lson,ll,rr)+read(rson,ll,rr))%mod;
}
signed main()
{
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++) scanf("%lld",in+i);
    build(1,1,n);
    char q[10];
    for(int i=1,a,b,x;i<=m;i++)
    {
        scanf("%s",q);
        if(q[0]=='Q')
        {
            scanf("%lld%lld",&a,&b);
            printf("%lld\n",read(1,a,b));
        }
        else if(q[0]=='A')
        {
            scanf("%lld%lld%lld",&a,&b,&x);
            tplus(1,a,b,x);
        }
        else if(q[0]=='M')
        {
            scanf("%lld%lld%lld",&a,&b,&x);
            multi(1,a,b,x);
        }
    }
    return 0;
}
