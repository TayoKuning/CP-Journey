/*
Problem solve using coordinate compression and difference array
I think we could solve this problem by keep the current time and just sort both the arrive and end time
But i think this is a good solution for this kind of problem
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
	vector<pair<int,int>> customer;
	vector<int> barisan;
	int n; cin>>n;
	for(int i = 0; i < n; i++){
		int a, b; cin>>a>>b;
		customer.push_back({a, b});
		barisan.push_back(a);
		barisan.push_back(b);
	}

	//coordinate compression
	map<int, int> val_compress;
	sort(barisan.begin(), barisan.end());
	for(int i = 0; i < barisan.size(); i++){
		val_compress[barisan[i]] = i+1; 
	}
	for(auto &[a,b] : customer){
		a = val_compress[a]; b = val_compress[b];
	}

	// Ngitung
	sort(customer.begin(), customer.end());
	vector<int> diff((2*n)+2, 0);
	for(auto &[a,b] : customer){
		// cout<<a<<" "<<b<<endl;
		diff[a] = 1, diff[b] = -1;
	}
	
	int temp = 0, maks = 0;
	for(int i = 1; i <= (2*n) + 1; i++){
		// cout<<diff[i]<<" ";
		temp += diff[i];
		maks = max(maks, temp);
	}
	cout<<maks<<endl;
}
