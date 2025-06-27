const int N=1e7+1;
int spf[N];
void compute_spf()
{
    for(int i=1;i<N;i++)spf[i]=i;
    for(int i=2;i<N;i++)
    {
        int fl=(N/i);
        if(fl<i or spf[i]!=i)continue;
        for(int j=(i*i);j<N;j+=i)
            if(spf[j]==j)spf[j]=i;
    }
}
map<int,int> get_prime_factor(int x)
{
    map<int,int> cnt;
    while(spf[x]>1)
    {
        cnt[spf[x]]++;
        x/=spf[x];
    }
    return cnt;
}