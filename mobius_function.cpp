const int N=5e5+2;
int spf[N],mob[N];
void compute()
{
    for(int i=1;i<N;i++)spf[i]=i,mob[i]=1;;
    for(int i=2;i<N;i++)
    {
        if(spf[i/spf[i]]==spf[i])
        {
            mob[i]=0;
        }
        else
        {
            mob[i]=-1*mob[i/spf[i]];
        }
        int fl=(N/i);
        if(fl<i or spf[i]!=i)continue;
        for(int j=(i*i);j<N;j+=i)
            if(spf[j]==j)spf[j]=i;
    }
}