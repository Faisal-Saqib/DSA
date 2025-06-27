ll powmod(ll a,ll b,ll& modd)
{
    if(b==0)return 1;
    ll fp=powmod(a,b/2,modd);
    fp=(fp*fp)%modd;
    if(b&1)
        fp=(fp*a)%modd;
    return fp;
}