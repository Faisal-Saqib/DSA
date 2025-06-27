#include <bits/stdc++.h>

using namespace std;

const int N=2e5+10;
vector<int> path,ma[N];
int node=1,in[N],out[N];
map<string,int> mp;
map<int,string> pm;

void dfs(int x)
{
    while(ma[x].size()>0)
    {
        int y=ma[x].back();
        ma[x].pop_back();
        dfs(y);
    }
    path.push_back(x);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        char a,b,c;
        cin>>a>>b>>c;
        string s1="";s1+=a;s1+=b;
        string s2="";s2+=b;s2+=c;
        if(mp.find(s1)==mp.end())
            mp[s1]=node++;
        
        if(mp.find(s2)==mp.end())
            mp[s2]=node++;
        
        int x=mp[s1],y=mp[s2];

        in[y]++;
        out[x]++;
        ma[x].push_back(y);
    }

    int c1=0,c2=0;
    for(int i=1;i<node;i++)
    {
        c1+=(in[i]>out[i]);
        c2+=(in[i]<out[i]);
        if(abs(in[i]-out[i])>1 or c1>1 or c2>1)
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }

    if(c2>0)
    {
        for(int i=1;i<node;i++)
        {
            if(in[i]<out[i])
            {
                dfs(i);
                break;
            }
        }
    }
    else
    {
        dfs(1);
    }
    if(path.size()!=(n+1))
    {
        cout<<"NO"<<endl;
        return 0;
    }
    for(auto&i:mp)
        pm[i.second]=i.first;
    
    reverse(begin(path),end(path));

    cout<<"YES"<<endl;
    cout<<pm[path[0]];
    for(int i=1;i<path.size();i++)
        cout<<pm[path[i]][1];
    cout<<endl;
}