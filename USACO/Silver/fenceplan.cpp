/*
Quite long but no fatal bug
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int>> adj;
vector<pair<int,int>> pos;
vector<bool> visited;
int mxx, mxy, mnx, mny;
int cnt;

void add(int x, int y){
    adj[x].push_back(y);
    adj[y].push_back(x);
}

void dfs(int now){
    visited[now] = true;
    for(auto next : adj[now]){
        if(visited[next]) continue;
        mxx = max(mxx, pos[next].first);
        mnx = min(mnx, pos[next].first);
        mxy = max(mxy, pos[next].second);
        mny = min(mny, pos[next].second);
        dfs(next);
    }
}

signed main(){
    freopen("fenceplan.in", "r", stdin);
	freopen("fenceplan.out", "w", stdout);
    int n, m; cin>>n>>m;
    adj.resize(n+1); pos.resize(n+1), visited.resize(n+1);

    for(int i = 1; i <= n; i++){
        int x, y; cin>>x>>y;
        pos[i] = {x,y};
    }

    for(int i = 1; i <= m; i++){
        int x, y; cin>>x>>y;
        add(x,y);
    }

    int minperi = 4 * 1e8;
    for(int i = 1; i <= n; i++){
        if(visited[i]) continue;
        mxx = mnx = pos[i].first;
        mxy = mny = pos[i].second;
        dfs(i);
        int xx = mxx - mnx, yy = mxy - mny;
        minperi = min(minperi, (2 * xx) + (2 * yy));
    }

    cout<<minperi<<endl;
}
