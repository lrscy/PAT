#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000 + 10;

struct Node {
	string a, b;
	int c;
}node[MAXN];
int n, c;

bool cmp( const Node &a, const Node &b ) {
	if( c == 1 ) return a.a < b.a;
	if( c == 2 ) return a.b == b.b ? a.a < b.a : a.b <= b.b;
	return a.c == b.c ? a.a < b.a : a.c <= b.c;
}

int main() {
	char st1[10], st2[10];
	int num;
	scanf( "%d%d", &n, &c );
	for( int i = 0; i < n; ++i ) {
		scanf( "%s%s%d", st1, st2, &num );
		node[i] = Node{ st1, st2, num };
	}
	sort( node, node + n, cmp );
	for( int i = 0; i < n; ++i ) {
		printf( "%s %s %d\n", node[i].a.c_str(), node[i].b.c_str(), node[i].c );
	}
	return 0;
}
