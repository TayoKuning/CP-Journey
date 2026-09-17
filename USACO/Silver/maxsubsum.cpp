/*
https://cses.fi/problemset/task/1643/
EASY
grab the minimum subarray and subtract it to the prefix at the time
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define bismillah ios_base::sync_with_stdio(false); cin.tie(NULL);

signed main(){
    bismillah
    int n; cin>>n;
    vector<int> barisan;

    for(int i = 0 ; i < n; i++){
        int x; cin>>x;
        barisan.push_back(x);
    }
    int prefixmin = 0, prefix = barisan[0],  maxx = barisan[0];
    prefixmin = min(prefixmin, barisan[0]);
    for(int i = 1; i < n; i++){
        prefix += barisan[i];
        maxx = max(maxx, prefix - prefixmin);
        prefixmin = min(prefix, prefixmin);
    }

    cout<<maxx<<endl;
}
