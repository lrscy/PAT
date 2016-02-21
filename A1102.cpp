#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100 + 10;

struct Node { int l, r; };
Node node[MAXN];
vector<int> vec;
int que[MAXN];
bool flag[MAXN];
int n;

void dfs( int u ) {
	if( ~node[u].r ) dfs( node[u].r );
	vec.push_back( u );
	if( ~node[u].l ) dfs( node[u].l );
	return ;
}

int main() {
	int mf, me;
	char s1[5], s2[5];
	memset( node, -1, sizeof( node ) );
	memset( flag, false, sizeof( flag ) );
	scanf( "%d", &n );
	if( !n ) { puts( "" ); return 0; }
	for( int i = 0; i < n; ++i ) {
		scanf( "%s%s", s1, s2 );
		if( s1[0] != '-' ) { flag[s1[0] - '0'] = true; node[i].l = s1[0] - '0'; }
		else node[i].l = -1;
		if( s2[0] != '-' ) { flag[s2[0] - '0'] = true; node[i].r = s2[0] - '0'; }
		else node[i].r = -1;
	}
	int root = -1;
	for( int i = 0; i < n; ++i ) if( !flag[i] ) { root = i; break; }
	mf = me = 0; que[me++] = root;
	while( mf < me ) {
		int u = que[mf++];
		vec.push_back( u );
		if( ~node[u].r ) que[me++] = node[u].r;
		if( ~node[u].l ) que[me++] = node[u].l;
	}
	for( int i = 0; i < n - 1; ++i ) printf( "%d ", vec[i] ); printf( "%d\n", vec[n - 1] );
	vec.clear(); dfs( root );
	for( int i = 0; i < n - 1; ++i ) printf( "%d ", vec[i] ); printf( "%d\n", vec[n - 1] );
	return 0;
}
