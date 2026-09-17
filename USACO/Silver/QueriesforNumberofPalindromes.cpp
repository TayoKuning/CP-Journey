/*
Silver - Normal
Problem that combine dp and prefix sum, such an interesting question
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define bismillah ios_base::sync_with_stdio(false); cin.tie(NULL);

signed main(){
    bismillah
    string s; cin>>s;
    int size = s.size();
    vector<char> alp; alp.push_back('0');
    for(int i = 0; i < size; i++) alp.push_back(s[i]);
    int dp[size+1][size+1];
    bool pal[size+1][size+1];

    for(int i = size; i >= 1; i--){
        dp[i][i] = 1; pal[i][i] = true;
        for(int j = i+1; j <= size; j++){
            dp[i][j] = dp[i+1][j] + dp[i][j-1];
            if(i+1 == j){
                if(alp[i] == alp[j]){
                    pal[i][j] = true;
                    dp[i][j] += 1;
                }else{
                    pal[i][j] = false;
                }
            }else{
                dp[i][j] -= dp[i+1][j-1];
                if(pal[i+1][j-1] && alp[i] == alp[j]){
                    dp[i][j]++; 
                    pal[i][j] = true;
                }else pal[i][j] = false;
            }
        }
    }
    int q; cin>>q;
    while(q--){
        int l, r; cin>>l>>r;
        cout<<dp[l][r]<<endl;
    }
}
