#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100 + 10;

vector<int> g[MAXN];
int que[MAXN];
int n, m, ans, ansl, cnt;

int main() {
	int k, t, tmp, mf, me;
	scanf( "%d%d", &n, &m );
	for( int i = 0; i < m; ++i ) {
		scanf( "%d%d", &t, &k );
		for( int j = 0; j < k; ++j ) {
			scanf( "%d", &tmp );
			g[t].push_back( tmp );
		}
	}
	mf = me = 0; que[me++] = 1; tmp = me;
	ans = cnt = 1; ansl = 1;
	while( mf != me ) {
		int u = que[mf++];
		if( mf >= MAXN ) mf -= MAXN;
		for( int i = 0; i < g[u].size(); ++i ) {
			que[me++] = g[u][i];
			if( me >= MAXN ) me -= MAXN;
		}
		if( mf == tmp ) {
			++cnt;
			if( ans < ( me - mf + MAXN ) % MAXN ) {
				ans = ( me - mf + MAXN ) % MAXN;
				ansl = cnt;
			}
			tmp = me;
		}
	}
	printf( "%d %d\n", ans, ansl );
	return 0;
}
