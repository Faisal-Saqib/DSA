#include <iostream>
#include <climits>
#include <vector>
#include <set>

using namespace std;

#define int long long

int n;
const int MAXN=1e5+10;
//          to  cost
vector<pair<int,int>> ma[MAXN];

void Dijkstra(){
	int dist[n+1];
	int pre[n+1];
	for(int i=1;i<=n;i++){
		dist[i]=LLONG_MAX;
	}
	int sc=1;
	cin>>sc;
	dist[sc]=0;
	pre[sc]=-1;
	set<pair<int,int>> g={{0,sc}};
	while(g.size()){
		int f=begin(g)->second;
		// cout<<f<<endl;
		for(auto i:ma[f]){
			if(dist[i.first]>dist[f]+i.second){
				dist[i.first]=dist[f]+i.second;
				g.insert({dist[i.first],i.first});
				pre[i.first]=f;
			}
		}
		g.erase(begin(g));
	}
	for(int i=1;i<=n;i++){
		if(dist[i]==LLONG_MAX)
		{
			cout<<"Not possible"<<endl;
		}
		else
		{
			cout<<"Distance from "<<sc<<" to "<<i<<" is "<<dist[i]<<endl;
		}
	}
}
main(){
	int m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b,w;
		cin>>a>>b>>w;
		ma[a].push_back({b,w});
		ma[b].push_back({a,w});
	}
	Dijkstra();
	return 0;
}