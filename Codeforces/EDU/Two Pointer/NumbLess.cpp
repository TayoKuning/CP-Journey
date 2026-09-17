/*
Easy, just a technical question
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define bismillah ios_base::sync_with_stdio(false); cin.tie(NULL);

signed main(){
    bismillah
    
    int n, m; cin>>n>>m;
    vector<int> barisan1(n+1), barisan2(m+1);

    for(int i = 1; i <= n; i++) cin>>barisan1[i];
    for(int i = 1; i <= m; i++) cin>>barisan2[i];

    vector<int> stless;

    int idx1 = 1;
    for(int idx2 = 1; idx2 <= m; idx2++){
        while(idx1 <= n && barisan2[idx2] > barisan1[idx1]) idx1++;
        stless.push_back(idx1-1);
    }

    for(auto x : stless){
        cout<<x<<" ";
    }
    cout<<endl;
}
