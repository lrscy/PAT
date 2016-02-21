#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
const int MAXN = 1e6 + 10;

struct Node {
	int a, b, c;
	Node() {}
	Node( int _a, int _b, int _c ) { a = _a; b = _b; c = _c; }
}num[MAXN];
bool flag[MAXN];
vector<Node> v1, v2;
int n;

int main() {
	int root, a, b, c;
	scanf( "%d%d", &root, &n );
	for( int i = 0; i < n; ++i ) {
		scanf( "%d%d%d", &a, &b, &c );
		num[a] = Node( a, b, c );
	}
	int tmp = root;
	while( ~tmp ) {
		int tn = num[tmp].b;
		if( flag[abs( tn )] ) v2.push_back( num[tmp] );
		else { v1.push_back( num[tmp] ); flag[abs( tn )] = true; }
		tmp = num[tmp].c;
	}
	int ncnt = v1.size();
	for( int i = 0; i < ncnt; ++i ) {
		printf( "%05d %d ", v1[i].a, v1[i].b );
		if( i == ncnt - 1 ) puts( "-1" );
		else printf( "%05d\n", v1[i + 1].a );
	}
	ncnt = v2.size();
	for( int i = 0; i < ncnt; ++i ) {
		printf( "%05d %d ", v2[i].a, v2[i].b );
		if( i == ncnt - 1 ) puts( "-1" );
		else printf( "%05d\n", v2[i + 1].a );
	}
	return 0;
}
