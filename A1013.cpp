#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int MAXN = 1000 + 10;

struct Edge { int to, next; };
Edge es[MAXN * MAXN];
int head[MAXN], fa[MAXN];
bool flag[MAXN * MAXN];
int n, m, k, cnt;

void add( int u, int v ) {
	es[cnt].to = v; es[cnt].next = head[u]; head[u] = cnt++;
}

int mfind( int x ) { return x == fa[x] ? x : fa[x] = mfind( fa[x] ); }

void munion( int u, int v ) {
	int x = mfind( u );
	int y = mfind( v );
	if( x != y ) fa[x] = y;
	return ;
}

int main() {
	int u, v;
	memset( head, -1, sizeof( head ) );
	cnt = 0;
	scanf( "%d%d%d", &n, &m, &k );
	for( int i = 0; i < m; ++i ) {
		scanf( "%d%d", &u, &v );
		add( u, v ); add( v, u );
	}
	while( k-- ) {
		memset( flag, true, sizeof( flag ) );
		for( int i = 1; i <= n; ++i ) fa[i] = i;
		scanf( "%d", &u );
		for( int i = head[u]; ~i; i = es[i].next ) {
			flag[i] = flag[i ^ 1] = false;
		}
		for( int i = 0; i < cnt; ++i ) {
			if( flag[i] ) munion( es[i ^ 1].to, es[i].to );
		}
		int cnt = 0;
		for( int i = 1; i <= n; ++i ) {
			if( i != u && fa[i] == i ) ++cnt;
		}
		printf( "%d\n", cnt - 1 );
	}
	return 0;
}
