#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
const int INF = 0x3F3F3F3F;
const int MAXN = 1000 + 10;
const int MAXM = 1000000 + 10;

struct Edge { int to, cost, next; };
Edge es[MAXM];
int head[MAXN], cost[MAXN], dis[MAXN], have[MAXN], que[MAXM], send[MAXN];
int pre[MAXN], sta[MAXN];
bool vis[MAXN];
int n, m, c, cnt, src, des;

void add( int u, int v, int w ) {
	es[cnt].to = v; es[cnt].cost = w; es[cnt].next = head[u]; head[u] = cnt++;
}

void spfa() {
	int mf, me;
	memset( vis, false, sizeof( vis ) );
	memset( dis, 0x3F, sizeof( dis ) );
	memset( pre, -1, sizeof( pre ) );
	mf = me = 0;
	send[src] = have[src] = 0; dis[src] = 0; vis[src] = true; que[me++] = src;
	while( mf != me ) {
		int u = que[mf++];
		if( mf >= MAXM ) mf -= MAXM;
		vis[u] = false;
		for( int i = head[u]; ~i; i = es[i].next ) {
			int v = es[i].to;
			if( dis[v] > dis[u] + es[i].cost ) {
				dis[v] = dis[u] + es[i].cost;
				send[v] = send[u] + min( 0, have[u] + cost[v] );
				have[v] = max( 0, have[u] + cost[v] );
				pre[v] = u;
				if( !vis[v] ) {
					vis[v] = true;
					que[me++] = v;
					if( me >= MAXM ) me -= MAXM;
				}
			} else if( dis[v] == dis[u] + es[i].cost ) {
				if( send[v] < send[u] + min( 0, have[u] + cost[v] ) ) {
					send[v] = send[u] + min( 0, have[u] + cost[v] );
				have[v] = max( 0, have[u] + cost[v] );
					pre[v] = u;
					if( !vis[v] ) {
						vis[v] = true;
						que[me++] = v;
						if( me >= MAXM ) me -= MAXM;
					}
				} else if( send[v] == send[u] + min( 0, have[u] + cost[v] ) ) {
					if( have[v] > have[u] + cost[v] ) {
						have[v] = have[u] + cost[v];
						pre[v] = u;
						if( !vis[v] ) {
							vis[v] = true;
							que[me++] = v;
							if( me >= MAXM ) me -= MAXM;
						}
					}
				}
			}
		}
	}
	return ;
}

int main() {
	int u, v, w, ncnt;
	memset( head, -1, sizeof( head ) );
	cnt = 0; src = 0;
	scanf( "%d%d%d%d", &c, &n, &des, &m );
	for( int i = 1; i <= n; ++i ) { scanf( "%d", cost + i ); cost[i] -= c / 2; }
	for( int i = 0; i < m; ++i ) {
		scanf( "%d%d%d", &u, &v, &w );
		add( u, v, w ); add( v, u, w );
	}
	spfa();
	printf( "%d ", -send[des] );
	u = des; ncnt = 0;
	sta[ncnt++] = u;
	while( ~pre[u] ) {
		u = pre[u];
		sta[ncnt++] = u;
	}
	for( int i = ncnt - 1; i; --i ) printf( "%d->", sta[i] );
	printf( "%d %d\n", sta[0], have[des] );
	return 0;
}
