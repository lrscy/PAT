#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100 + 10;

struct Node {
	int val, l, r, lcnt, rcnt;
}node[MAXN];
bool flag[MAXN];
int a[MAXN], que[MAXN];
vector<int> vec;
int n;

int dfs( int u ) {
	if( ~node[u].l ) node[u].lcnt = dfs( node[u].l );
	if( ~node[u].r ) node[u].rcnt = dfs( node[u].r );
	return node[u].lcnt + node[u].rcnt + 1;
}

void dfs2( int u, int l, int r ) {
	node[u].val = a[l + node[u].lcnt];
	if( node[u].lcnt ) dfs2( node[u].l, l, l + node[u].lcnt - 1 );
	if( node[u].rcnt ) dfs2( node[u].r, r - node[u].rcnt + 1, r );
	return ;
}

int main() {
	int x, y;
	scanf( "%d", &n );
	if( !n ) { puts( "" ); return 0; }
	for( int i = 0; i < n; ++i ) {
		scanf( "%d%d", &node[i].l, &node[i].r );
		if( ~node[i].l ) flag[node[i].l] = true;
		if( ~node[i].r ) flag[node[i].r] = true;
	}
	for( int i = 0; i < n; ++i ) scanf( "%d", a + i );
	sort( a, a + n );
	int root;
	for( int i = 0; i < n; ++i ) if( !flag[i] ) { root = i; break; }
	dfs( root );
	dfs2( root, 0, n - 1 );
	int mf, me; mf = me = 0;
	que[me++] = root;
	while( mf < me ) {
		int u = que[mf++];
		vec.push_back( node[u].val );
		if( ~node[u].l ) que[me++] = node[u].l;
		if( ~node[u].r ) que[me++] = node[u].r;
	}
	for( int i = 0; i + 1 < vec.size(); ++i ) printf( "%d ", vec[i] );
	printf( "%d\n", vec[vec.size() - 1] );
	return 0;
}
