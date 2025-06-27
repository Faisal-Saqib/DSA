const ll N=1e6+1;
const ll mod=1e9+7;
ll fac[N],ifac[N];
ll powmod(ll a,ll b,ll& modd)
{
    if(b==0)return 1;
    ll fp=powmod(a,b/2,modd);
    fp=(fp*fp)%modd;
    if(b&1)
        fp=(fp*a)%modd;
    return fp;
}
void compute()
{
	fac[0]=1;
    for(ll i=1;i<N;i++)
        fac[i]=(fac[i-1]*i)%mod;
    ifac[N-1]=powmod(fac[N-1],mod-2,mod);
    for(ll i=N-2;i>=0;i--)
        ifac[i]=(ifac[i+1]*(i+1))%mod;   
}
ll nCr(ll n,ll r)
{
    if(n<0)return 0;
    if(r<0)return 0;
    if(n<r)return 0;
    return (((fac[n]*ifac[r])%mod)*ifac[n-r])%mod;
}