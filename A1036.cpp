#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

struct Node {
	string name, gender, obj;
	int score;
	bool operator < ( const Node &tmp ) const {
		return score < tmp.score;
	}
}nodea[MAXN], nodeb[MAXN];
int n, c1, c2;

int main() {
	Node tmp;
	cin >> n;
	c1 = c2 = 0;
	for( int i = 0; i < n; ++i ) {
		cin >> tmp.name >> tmp.gender >> tmp.obj >> tmp.score;
		if( tmp.gender == "M" ) nodea[c1++] = tmp;
		else nodeb[c2++] = tmp;
	}
	if( c1 ) sort( nodea, nodea + c1 );
	if( c2 ) sort( nodeb, nodeb + c2 );
	if( c1 && c2 ) {
		int tmp = nodeb[c2 - 1].score - nodea[0].score;
		cout << nodeb[c2 - 1].name << " " << nodeb[c2 - 1].obj << endl;
		cout << nodea[0].name << " " << nodea[0].obj << endl;
		cout << tmp << endl;
	} else {
		if( c2 ) cout << nodeb[c2 - 1].name << " " << nodeb[c2 - 1].obj << endl;
		else cout << "Absent" << endl;
		if( c1 ) cout << nodea[0].name << " " << nodea[0].obj << endl;
		else cout << "Absent" << endl;
		cout << "NA" << endl;
	}
	return 0;
}
