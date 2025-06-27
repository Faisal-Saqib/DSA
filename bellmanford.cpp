#include <iostream>
#include <vector>

using namespace std;

const int INF=2e7;
const int MAXN=1e5;
vector<int> v[MAXN];
int dist[MAXN];
int n,m;

void bellman_ford(int sr)
{
	for(int i=0;i<=n;i++){
		dist[i]=INF;
	}
	dist[sr]=0;
	for(int i=0;i<n-1;i++)
		for(int j=0;j<m;j++)
			if(dist[v[j][0]]+v[j][2]<dist[v[j][1]])
				dist[v[j][1]]=dist[v[j][0]]+v[j][2];
	for (int i = 0; i < m; i++) {
        int x = v[i][0];
        int y = v[i][1];
        int weight = v[i][2];
        if(dist[y]  > dist[x] + weight){
            cout<<"Graph has a negative  cycle"<<endl;
            break;
        }
    }
    cout << "Vertex Distance from Source" << endl;
    for (int i = 1; i <=n; i++)
        cout << i << "\t\t" << dist[i] << endl;
}

int main()
{
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		v[i].push_back(a);
		v[i].push_back(b);
		v[i].push_back(c);
	}
	int scr=1;
	cout<<"Tell me source"<<endl;
	cin>>scr;
	bellman_ford(scr);
	return 0;
}