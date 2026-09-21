/*
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int n, s; cin>>n>>s;
    vector<int> barisan(n+1);
    for(int i = 1; i <= n; i++){
        cin>>barisan[i];
    }

    int id = 1, sum = 0, len = 0, ans = 0;
    for(int i = 1; i <= n; i++){
        sum += barisan[i]; len++;
        if(sum > s){            
            while(id <= i && sum > s){
                sum -= barisan[id]; len--;
                id++;
            }
        }
        if(sum <= s) ans = max(len, ans);
    }

    cout<<ans<<endl;
    
}
