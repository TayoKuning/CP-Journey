#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int> barisan;
int n, q; 

signed main(){
    freopen("haybales.in", "r", stdin);
	freopen("haybales.out", "w", stdout);
    cin>>n>>q;
    barisan.resize(n+1); barisan[0] = 0;
    for(int i = 1; i <= n; i++) cin>>barisan[i];
    sort(barisan.begin(), barisan.end());
    while(q--){
        int a, b; cin>>a>>b;
        int ansl = n+1, ansr = -1;

        int l = 1, r = n;
        while(l <= r){
            int mid = (l+r)/2;
            if(a <= barisan[mid]){
                ansl = mid;
                // cout<<ansl<<" ";
                r = mid - 1;
            }else l = mid+1;
        }

        l = 1, r = n;
        while(l <= r){
            int mid = (l+r)/2;
            if(b >= barisan[mid]){
                ansr = mid;
                l = mid + 1;
            }else r = mid - 1;
        }

        // cout<<ansl<<" "<<ansr<<endl;
        cout<<ansr - ansl + 1<<endl;
    }
}
