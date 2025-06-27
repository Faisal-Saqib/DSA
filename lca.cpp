const ll N=2e5+1;
const ll LG=18;
vll ma[N];
ll h[N],par[N][LG];
void dfs(int x,int p=-1)
{
	for(int j=1;j<LG;j++)
		par[x][j]=par[par[x][j-1]][j-1];
	for(auto y:ma[x])
	{
		if(y==p)continue;
		h[y]=h[x]+1;
		par[y][0]=x;
		dfs(y,x);
	}
}
int lca(int x,int y)
{
	if(h[x]<h[y])
		swap(x,y);
	for(int j=LG-1;j>=0;j--)
	{
		if(h[par[x][j]]>=h[y])
		{
			x=par[x][j];
		}
	}
	if(x==y)
	{
		return x;
	}
	for(int j=LG-1;j>=0;j--)
	{
		if(par[x][j]!=par[y][j])
		{
			x=par[x][j];
			y=par[y][j];
		}
	}
	return par[x][0];
}
int dist(int x,int y)
{
	return h[x]+h[y]-2*h[lca(x,y)];
}