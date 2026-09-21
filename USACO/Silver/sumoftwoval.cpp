/*
Really give me a headache when debug the two pointer XD
But i think its give me a better understanding in two pointer
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int n, x; cin>>n>>x;
    vector<pair<int,int>> barisan;
    for(int i = 0; i < n;  i++){
        int x; cin>>x;
        barisan.push_back({x, i+1});
    }

    sort(barisan.begin(), barisan.end());

    int id1 = 0, id2 = n-1;
    
    while(id1 < id2){
        if(barisan[id1].first + barisan[id2].first == x){
            cout<<barisan[id1].second<<" "<<barisan[id2].second<<endl;
            return 0;
        }
        if(barisan[id1].first + barisan[id2].first < x) id1++;
        if(barisan[id1].first + barisan[id2].first > x) id2--;
    }

    cout<<"IMPOSSIBLE"<<endl;
    
}
