#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;
const int INF = 0x3F3F3F3F;
const int MAXN = 1000 + 10;

int t[MAXN], st[MAXN], win[25];
queue<int> que[25];
int n, m, k, q;

int main() {
	int i;
	memset( win, 0, sizeof( win ) );
	scanf( "%d%d%d%d", &n, &m, &k, &q );
	for( i = 0; i < k; ++i ) scanf( "%d", t + i );
	for( i = 0; i < min( k, n * m ); ++i ) {
		st[i] = win[i % n];
		que[i % n].push( i );
		win[i % n] += t[i];
	}
	for( ; i < k; ++i ) {
		int nmin = INF, pos;
		for( int j = 0; j < n; ++j ) {
			int tmp = que[j].front();
			if( st[tmp] + t[tmp] < nmin ) {
				nmin = st[tmp] + t[tmp];
				pos = j;
			}
		}
		que[pos].pop();
		que[pos].push( i );
		st[i] = win[pos];
		win[pos] += t[i];
	}
	while( q-- ) {
		scanf( "%d", &n ); --n;
		if( st[n] >= 540 ) { puts( "Sorry" ); continue; }
		printf( "%02d:%02d\n", ( st[n] + t[n] ) / 60 + 8, ( st[n] + t[n] ) % 60 );
	}
	return 0;
}
