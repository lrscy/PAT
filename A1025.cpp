#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000 + 10;

struct Node {
	string num;
	int s, fr, ln, lr;
	Node() {}
	Node( string _num, int _s, int _ln ) : num( _num ), s( _s ), ln( _ln ) {}
}node[MAXN];
int n, k;

bool cmp( const Node &a, const Node &b ) {
	return a.s == b.s ? a.num < b.num : a.s > b.s;
}

int main() {
	char str[20];
	int ts, cnt = 0;
	scanf( "%d", &n );
	for( int i = 0; i < n; ++i ) {
		scanf( "%d", &k );
		if( !k ) continue;
		int scnt = cnt;
		for( int j = 0; j < k; ++j ) {
			scanf( "%s%d", str, &ts );
			node[cnt++] = Node( str, ts, i + 1 );
		}
		sort( node + scnt, node + cnt, cmp );
		node[scnt].lr = 1;
		for( int j = scnt + 1; j < cnt; ++j ) {
			if( node[j].s == node[j - 1].s ) node[j].lr = node[j - 1].lr;
			else node[j].lr = j - scnt + 1;
		}
	}
	sort( node, node + cnt, cmp );
	node[0].fr = 1;
	for( int i = 1; i < cnt; ++i ) {
		if( node[i].s == node[i - 1].s ) node[i].fr = node[i - 1].fr;
		else node[i].fr = i + 1;
	}
	printf( "%d\n", cnt );
	for( int i = 0; i < cnt; ++i ) {
		printf( "%s %d %d %d\n", node[i].num.c_str(), node[i].fr, node[i].ln, node[i].lr );
	}
	return 0;
}
