#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> pos;
vector<int> power;
vector<bool> visited;
int n, cnt;

void bfs(int now, int pow){
    visited[now] = true;
    auto [x1,y1] = pos[now];
    for(int i = 1; i <= n; i++){
        if(visited[i]) continue;
        auto [x2,y2] = pos[i];
        long long dx = x1 - x2;
        long long dy = y1 - y2;

        if(dx * dx + dy * dy <= pow * pow){
            cnt++;
            bfs(i, power[i]);
        }
    }
}

signed main(){
    freopen("moocast.in", "r", stdin);
	freopen("moocast.out", "w", stdout);
    cin>>n;
    pos.resize(n+1);
    power.resize(n+1);
    visited.resize(n+1);

    for(int i = 1; i <= n; i++){
        int x, y, p; cin>>x>>y>>p;
        pos[i] = {x,y}; power[i] = p;
    }

    int maks = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) visited[j] = false;
        cnt = 0; cnt++;
        bfs(i, power[i]);
        maks = max(cnt, maks);
    }
    cout<<maks<<endl;
}
