#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int INF = 0x3F3F3F3F;
const int MAXN = 100000 + 10;

struct Edge { int to, next; };
Edge es[MAXN];
int head[MAXN], dis[MAXN], fa[MAXN];
bool vis[MAXN];
int n, m, cnt, root, dmax;

void add( int u, int v ) {
	es[cnt].to = v; es[cnt].next = head[u]; head[u] = cnt++;
	es[cnt].to = u; es[cnt].next = head[v]; head[v] = cnt++;
	return ;
}

int mfind( int x ) { return x == fa[x] ? x : fa[x] = mfind( fa[x] ); }

void munion( int u, int v ) {
	int x = mfind( u ), y = mfind( v );
	if( x != y ) fa[x] = y;
	return ;
}

void dfs( int u, int fa, int level ) {
	dis[u] = level;
	dmax = max( dmax, level );
	for( int i = head[u]; ~i; i = es[i].next ) {
		int v = es[i].to;
		if( v == fa ) continue;
		dfs( v, u, level + 1 );
	}
	return ;
}

int main() {
	int u, v;
	memset( head, -1, sizeof( head ) );
	cnt = 0;
	scanf( "%d", &n );
	for( int i = 1; i <= n; ++i ) fa[i] = i;
	for( int i = 1; i < n; ++i ) {
		scanf( "%d%d", &u, &v );
		add( u, v );
		munion( u, v );
	}
	int ncnt = 0;
	for( int i = 1; i <= n; ++i ) if( fa[i] == i ) ++ncnt;
	if( ncnt > 1 ) { printf( "Error: %d components\n", ncnt ); return 0; }
	memset( vis, false, sizeof( vis ) );
	memset( dis, 0x3F, sizeof( dis ) );
	root = 1; dmax = 0;
	dfs( root, -1, 0 );
	for( int i = 1; i <= n; ++i ) {
		if( dis[i] == dmax ) {
			vis[i] = true;
			root = i;
		}
	}
	memset( dis, 0x3F, sizeof( dis ) );
	dmax = 0;
	dfs( root, -1, 0 );
	for( int i = 1; i <= n; ++i ) if( dis[i] == dmax ) vis[i] = true;
	for( int i = 1; i <= n; ++i ) if( vis[i] ) printf( "%d\n", i );
	return 0;
}
