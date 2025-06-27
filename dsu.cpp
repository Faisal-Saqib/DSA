const int N=1e5+1;
int par[N];
void init(int n)
{
	for(int i=1;i<=n;i++)par[i]=i;
}
int get(int x)
{
	return ((par[x]==x)?x:par[x]=get(par[x]));
}
void merge(int x,int y)
{
	par[get(x)]=get(y);	
}