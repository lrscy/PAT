#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int MAXN = 100 + 10;
const int MAXM = 1000 + 10;

struct Edge { int to, next; };
Edge es[MAXM];
int head[MAXN], tot[MAXN], que[MAXM];
int n, m, k, cnt, lcnt;

void add( int u, int v ) {
	es[cnt].to = v; es[cnt].next = head[u]; head[u] = cnt++;
	return ;
}

void bfs() {
	int mf, me, flag;
	memset( tot, 0, sizeof( tot ) );
	mf = me = 0;
	que[me++] = 1; flag = me;
	while( mf != me ) {
		int tcnt = 0;
		while( mf != flag ) {
			int u = que[mf++];
			bool tf = false;
			for( int i = head[u]; ~i; i = es[i].next ) {
				int v = es[i].to;
				que[me++] = v;
				tf = true;
			}
			if( !tf ) ++tcnt;
		}
		tot[lcnt] = tcnt;
		flag = me;
		++lcnt;
	}
	return ;
}

int main() {
	int u, v;
	memset( head, -1, sizeof( head ) );
	scanf( "%d%d", &n, &m );
	for( int i = 0; i < m; ++i ) {
		scanf( "%d%d", &u, &k );
		for( int j = 0; j < k; ++j ) {
			scanf( "%d", &v );
			add( u, v );
		}
	}
	lcnt = 0;
	bfs();
	printf( "%d", tot[0] );
	for( int i = 1; i < lcnt; ++i ) printf( " %d", tot[i] );
	puts( "" );
	return 0;
}
