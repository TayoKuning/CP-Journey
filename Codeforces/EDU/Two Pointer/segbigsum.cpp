/*
It kinda similar with the previous problem segsmallsum
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int n, s; cin>>n>>s;
    vector<int> barisan(n+1);
    int id1 = 1, id2 = 1, sum = 0, len = 0, ans = n+1;
    for(int i = 1; i <= n; i++){
        cin>>barisan[i];
    }

    while(id2 <= n){
        sum += barisan[id2]; len++; id2++;
        while(sum >= s){
            if(sum >= s) ans = min(ans, len);
            sum -= barisan[id1]; len--; id1++;
        }
    }

    if(ans > n) ans = -1;
    cout<<ans<<endl;
    
}
