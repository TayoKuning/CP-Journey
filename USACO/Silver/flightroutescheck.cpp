#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int>> adj, badj;
vector<bool> visited;

void add(int x, int y){
    adj[x].push_back(y);
    badj[y].push_back(x);
}

void bdfs(int now){
    visited[now] = true;
    for(auto next : badj[now]){
        if(visited[next]) continue;
        bdfs(next);
    }
}

void dfs(int now){
    visited[now] = true;
    for(auto next : adj[now]){
        if(visited[next]) continue;
        dfs(next);
    }
}

signed main(){
    int n, m; cin>>n>>m;
    adj.resize(n+1), badj.resize(n+1), visited.resize(n+1);

    for(int i = 1; i <= m; i++){
        int x, y; cin>>x>>y;
        add(x,y);
    }

    dfs(1);

    for(int i = 2; i <= n; i++){
        if(!visited[i]){
            cout<<"NO"<<endl;
            cout<<1<<" "<<i<<endl;
            return 0;
        }
    }

    for(int i = 1; i <= n; i++) visited[i] = false;

    bdfs(1);

    for(int i = 2; i <= n; i++){
        if(!visited[i]){
            cout<<"NO"<<endl;
            cout<<i<<" "<<1<<endl;
            return 0;
        }
    }
    
    cout<<"YES"<<endl;
}
