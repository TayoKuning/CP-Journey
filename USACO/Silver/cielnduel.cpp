/*
My first codeforces with rating 1900
kinda ez (its an usaco silver medium level) but still a careful implementation
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int> xat, yat, ydef;
int defsisa = 0, defhabis = 0;
int szxat = 0, szyat = 0, szydef = 0;
int n, m; 

int habis(int makan){
    vector<int> sxat = xat;
    int idx_sxat = 1;
    for(auto x : ydef){
        if(idx_sxat > m){
            defhabis = -1;
            return -1;
        }
        if(x == -1) continue;
        while(sxat[idx_sxat] <= x){
            idx_sxat++;
            if(idx_sxat > m){
                defhabis = -1;
                return -1;
            }
        }
        sxat[idx_sxat] = -1;
        idx_sxat++;
    }
    //hitung atk
    idx_sxat = 1;
    for(auto x : yat){
        if(idx_sxat > m){
            defhabis = -1;
            return -1;
        }
        if(x == -1) continue;
        while(sxat[idx_sxat] < x){
            idx_sxat++;
            if(idx_sxat > m){
                defhabis = -1;
                return -1;
            }
        }
        defhabis += sxat[idx_sxat] - x;
        sxat[idx_sxat] = -1;
        idx_sxat++;
    }

    for(auto x : sxat){
        if(x != -1) defhabis += x;
    }
    return defhabis;
}

signed main(){
    cin>>n>>m; szxat = m;
    xat.push_back(-1);
    yat.push_back(-1);
    ydef.push_back(-1);

    for(int i = 0;  i< n ; i++){
        string x; int y; cin>>x>>y;
        if(x == "ATK"){
            szyat++;
            yat.push_back(y);
        }else{
            ydef.push_back(y);
            szydef++;
        }
    }

    for(int i = 0; i < m; i++){
        int x; cin>>x;
        xat.push_back(x);
    }

    sort(xat.begin(), xat.end());
    sort(yat.begin(), yat.end());
    sort(ydef.begin(), ydef.end());


    //Habisin defnya
    defhabis = habis(1000);
    //Optimalkan atknya
    int idx_xat = m, idx_yat = 1;
    while(xat[idx_xat] >= yat[idx_yat] && idx_xat >= 1 && idx_yat <= szyat){
        defsisa += xat[idx_xat] - yat[idx_yat];
        idx_xat--; idx_yat++;
    }
    
    cout<<max(defhabis, defsisa)<<endl;
}
