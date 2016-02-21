#include <bits/stdc++.h>
using namespace std;
const int INF = 0x7F7F7F7F;
const int MAXN = 100 + 10;

int a[MAXN], b[MAXN], c[MAXN], d[MAXN];
int n;

int main() {
	scanf( "%d", &n );
	for( int i = 1; i <= n; ++i ) scanf( "%d", a + i ), d[i] = a[i];
	for( int i = 1; i <= n; ++i ) scanf( "%d", b + i ), c[i] = b[i];
	sort( c + 1, c + 1 + n );
	int pos = -1, flag = 0;
	for( int i = 2; i <= n; ++i ) {
		int x = upper_bound( d, d + i, d[i] ) - d, tmp = d[i];
		for( int j = i; j > x; --j ) d[j] = d[j - 1];
		d[x] = tmp;
		flag = 1;
		for( int j = 1; j <= n; ++j ) if( b[j] != d[j] ) { flag = 0; break; }
		if( flag ) { pos = i + 1; break; }
	}
	if( flag ) {
		puts( "Insertion Sort" );
		int x = upper_bound( d + 1, d + pos, d[pos] ) - d, tmp = d[pos];
		for( int j = pos; j > x; --j ) d[j] = d[j - 1];
		d[x] = tmp;
		for( int i = 1; i < n; ++i ) printf( "%d ", d[i] );
		printf( "%d\n", d[n] );
	} else {
		puts( "Heap Sort" );
		for( int i = n; i; --i ) {
			if( b[i] != c[i] ) { pos = i; break; }
		}
		swap( b[pos], b[1] ); --pos;
		int root = 1;
		while( root <= pos ) {
			int lson = ( root << 1 ), rson = ( root << 1 | 1 );
			if( lson <= pos && rson <= pos ) {
				int tmax = max( b[lson], b[rson] );
				int tpos = tmax == b[lson] ? lson : rson;
				if( b[root] < b[tpos] ) {
					swap( b[root], b[tpos] );
					root = tpos;
				} else break;
			} else if( lson <= pos ) {
				if( b[root] < b[lson] ) {
					swap( b[root], b[lson] );
					root = lson;
				} else break;
			} else if( rson <= pos ) {
				if( b[root] < b[rson] ) {
					swap( b[root], b[rson] );
					root = rson;
				} else break;
			} else break;
		}
		for( int i = 1; i < n; ++i ) printf( "%d ", b[i] );
		printf( "%d\n", b[n] );
	}
	return 0;
}
