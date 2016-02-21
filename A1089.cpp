#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100 + 10;

int a[MAXN], b[MAXN], c[MAXN];
int n;

int main() {
	scanf( "%d", &n );
	for( int i = 0; i < n; ++i ) scanf( "%d", a + i ), c[i] = a[i];
	for( int i = 0; i < n; ++i ) scanf( "%d", b + i );
	int pos;
	bool flag = true;
	for( int i = 1; i < n; ++i ) {
		int x = lower_bound( c, c + i, c[i] ) - c, tmp = c[i];
		for( int j = i; j > x; --j ) c[j] = c[j - 1];
		c[x] = tmp;
		flag = true;
		for( int j = 0; j < n; ++j ) if( b[j] != c[j] ) { flag = false; break; }
		if( flag ) { pos = i + 1; break; }
	}
	if( flag ) {
		puts( "Insertion Sort" );
		if( pos >= n ) {
			for( int i = 0; i < n - 1; ++i ) printf( "%d ", c[i] );
			printf( "%d\n", c[n - 1] );
			return 0;
		}
		int x = lower_bound( c, c + pos, c[pos] ) - c, tmp = c[pos];
		for( int j = pos; j > x; --j ) c[j] = c[j - 1];
		c[x] = tmp;
		for( int i = 0; i < n - 1; ++i ) printf( "%d ", c[i] );
		printf( "%d\n", c[n - 1] );
	} else {
		puts( "Merge Sort" );
		for( int i = 1; i <= n; i *= 2 ) {
			for( int j = 0; j <= n / i; ++j ) {
				sort( a + j * i, a + min( n, ( j + 1 ) * i ) );
			}
			flag = true;
			for( int j = 0; j < n; ++j ) if( a[j] != b[j] ) { flag = false; break; }
			if( flag ) {
				i *= 2;
				for( int j = 0; j <= n / i; ++j ) {
					sort( a + j * i, a + min( n, ( j + 1 ) * i ) );
				}
				break;
			}
		}
		for( int i = 0; i < n - 1; ++i ) printf( "%d ", a[i] );
		printf( "%d\n", a[n - 1] );
	}
	return 0;
}
