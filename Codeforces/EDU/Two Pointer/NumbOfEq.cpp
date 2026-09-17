/*
quite ez
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

    int idx1 = 1, idx2 = 1;
    int ans = 0;
    while(idx1 <= n && idx2 <= m){
        if(barisan1[idx1] == barisan2[idx2]){
            int base = barisan1[idx1], a = 0, b = 0;
            while(idx1 <= n && barisan1[idx1] == base){
                a++;
                idx1++;
            }
            while(idx2 <= m && barisan2[idx2] == base){
                b++;
                idx2++;
            }

            ans += a * b;
        }else{
            if(barisan1[idx1] < barisan2[idx2]) idx1++;
            else idx2++;
        }
    }

    cout<<ans<<endl;
}
