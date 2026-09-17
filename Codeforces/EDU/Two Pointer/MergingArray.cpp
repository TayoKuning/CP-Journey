/*
Quite Easy
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

    vector<int> nbarisan;

    int idx1 = 1, idx2 = 1;
    while(nbarisan.size() < n+m){
        if(barisan1[idx1] > barisan2[idx2]){
            nbarisan.push_back(barisan2[idx2]);
            idx2++;
        }else{
            nbarisan.push_back(barisan1[idx1]);
            idx1++;
        }

        if(idx1 > n){
            for(int i = idx2; i <= m; i++){
                nbarisan.push_back(barisan2[i]);
            }
        }else if(idx2 > m){
            for(int i = idx1; i <= n; i++){
                nbarisan.push_back(barisan1[i]);
            }
        }
    }

    for(auto x : nbarisan) cout<<x<<" ";
}
