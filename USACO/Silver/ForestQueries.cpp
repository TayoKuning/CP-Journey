// https://cses.fi/problemset/task/1652
/*
wrong index, where it should be (y,x) but I accidently write (x,y)
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int n, q; cin>>n>>q;
    int prefix[n+1][n+1];
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++) prefix[i][j] = 0;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
            char x; cin>>x;
            if(x == '*') prefix[i][j]++;
        }
    }

    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j <= n; j++){
    //         cout<<prefix[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    while(q--){
        int y1, x1, y2, x2; cin>>y1>>x1>>y2>>x2;
        cout<<prefix[y2][x2] - prefix[y2][x1-1] - prefix[y1-1][x2] + prefix[y1-1][x1-1]<<endl;
    }
}
