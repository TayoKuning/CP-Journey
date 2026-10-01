/*
Quite ez
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t; cin>>t;

    while(t--){
        int n, m; cin>>n>>m;
        vector<int> barisan(n+1); barisan[0] = 0;
        for(int i = 1; i <= n; i++) cin>>barisan[i];
        vector<int> sbarisan = barisan;
        sort(sbarisan.begin(), sbarisan.end());

        int cnt = 0, tot = 0, maks = 0;
        for(int i = 1; i <= n; i++){
            if(tot + sbarisan[i] > m) break;
            maks = max(maks, sbarisan[i]);
            tot += sbarisan[i];
            cnt++;
        }

        //idx yang ngalahin dia
        if(cnt + 1 > n){
            cout<<1<<endl; continue;
        }
        int idx_atas = cnt + 1;
        if(barisan[idx_atas] <= maks + (m - tot)){
            cout<<n - idx_atas + 1<<endl;
        }else cout<<n - idx_atas + 2<<endl;
    }
}
