#include <iostream>

using namespace std;
#define INF 1e6
const int MAXN=100;
int dist[MAXN][MAXN];
void fordwarshall(int n)
{
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
                if(dist[i][j]>(dist[i][k] + dist[k][j])){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
			}
		}
	}
}
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dist[i][j]=INF;
			dist[i][i]=0;
			dist[j][j]=0;
		}		
	}
	for(int i=0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		if(c==-1){
			continue;
		}
		dist[a][b]=c;
	}
	fordwarshall(n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<dist[i][j]<<' ';
		}
		cout<<endl;
	}
}