/*
My first custom comparator problem, quite ez but give me a new lesson about custom comparator
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Edge {
	int poin, pen;
	string name;

	bool operator<(const Edge &y) {
		if (poin != y.poin) { return poin > y.poin; }
        if (pen != y.pen) { return pen < y.pen; }
		return name < y.name;
	}
};

int main() {
    int n; cin>>n;

	vector<Edge> edges(n);
    for(int i = 0; i < n; i++){
        string x; cin>>x;
        int a, b, c, d; cin>>a>>b>>c>>d;
        int point = a + c, pena = b + d;
        edges[i].poin = point, edges[i].pen = pena, edges[i].name = x;
    }

	sort(edges.begin(), edges.end());

	for (const Edge &e : edges) { cout<<e.name<<endl;}
}
