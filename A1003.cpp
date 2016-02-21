#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int INF = 0x3F3F3F3F;
const int MAXN = 1000 + 10;
const int MAXM = 1000000 + 10;

struct Edge { int to, cost, next; };
Edge es[MAXM];
int head[MAXN], dis[MAXN], a[MAXN], tot[MAXN], dp[MAXN];
bool vis[MAXN];
int n, m, cnt, src, des;

void add( int u, int v, int c ) {
	es[cnt].to = v; es[cnt].cost = c; es[cnt].next = head[u]; head[u] = cnt++;
}

void dij() {
	memset( vis, false, sizeof( vis ) );
	memset( dis, 0x3F, sizeof( dis ) );
	memset( tot, 0, sizeof( tot ) );
	memset( dp, 0, sizeof( dp ) );
	dis[src] = 0; dp[src] = a[src]; tot[src] = 1;
	while( true ) {
		int v = -1;
		for( int u = 0; u < n; ++u ) if( !vis[u] && ( v == -1 || dis[u] < dis[v] ) ) v = u;
		if( v == -1 ) break;
		vis[v] = true;
		for( int i = head[v]; ~i; i = es[i].next ) {
			int u = es[i].to;
			if( dis[u] > dis[v] + es[i].cost ) {
				dis[u] = dis[v] + es[i].cost;
				tot[u] = tot[v];
				dp[u] = dp[v] + a[u];
			} else if( dis[u] == dis[v] + es[i].cost ) {
				tot[u] += tot[v];
				dp[u] = max( dp[u], dp[v] + a[u] );
			}
		}
	}
	return ;
}

int main() {
	int u, v, w;
	memset( head, -1, sizeof( head ) );
	memset( dp, 0, sizeof( dp ) );
	cnt = 0;
	scanf( "%d%d%d%d", &n, &m, &src, &des );
	for( int i = 0; i < n; ++i ) scanf( "%d", a + i );
	a[n] = 0;
	for( int i = 0; i < m; ++i ) {
		scanf( "%d%d%d", &u, &v, &w );
		add( u, v, w ); add( v, u, w );
	}
	dij();
	printf( "%d %d\n", tot[des], dp[des] );
	return 0;
}
