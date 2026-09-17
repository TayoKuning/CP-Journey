/*
At first I misunderstand the question mission, but after I read it again I understand the flaw in my solution before.
Maybe this is my first ICPC question that I answer (even though it just a regional question)
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define bismillah ios_base::sync_with_stdio(false); cin.tie(NULL);

signed main(){
    bismillah
    int n, m; cin>>n>>m;
    vector<int> barisan(n+1);

    for(int i = 1; i <= n; i++){
        cin>>barisan[i];
    }

    for(int i = 1; i < n; i++){
        if(abs(barisan[i] - barisan[i+1]) <= m) continue;
        if(barisan[i] < barisan[i+1]){
            barisan[i] = barisan[i+1] - m;
        }else{
            barisan[i+1] = barisan[i] - m;
        }
    }

    for(int i = n; i > 1; i--){
        if(abs(barisan[i] - barisan[i-1]) <= m) continue;
        if(barisan[i] < barisan[i-1]){
            barisan[i] = barisan[i-1] - m;
        }else{
            barisan[i-1] = barisan[i] - m;
        }
    }

    for(int i = 1; i <= n; i++){
        cout<<barisan[i]<<" ";
    }

    
}
