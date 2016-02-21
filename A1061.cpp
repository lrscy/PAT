#include <bits/stdc++.h>
using namespace std;
const int MAXN = 110;

char mp[10][10] = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };
char a[MAXN], b[MAXN], c[MAXN], d[MAXN];
int na, nb, nc, nd;

int main() {
	int i;
	scanf( "%s%s%s%s", a, b, c, d );
	na = strlen( a );
	nb = strlen( b );
	nc = strlen( c );
	nd = strlen( d );
	for( i = 0; i < na && i < nb; ++i ) {
		if( a[i] == b[i] && 'A' <= a[i] && a[i] <= 'G' ) {
			printf( "%s ", mp[a[i] - 'A'] );
			break;
		}
	}
	for( ++i; i < na && i < nb; ++i ) {
		if( a[i] == b[i] && ( ( 'A' <= a[i] && a[i] <= 'N' ) ||
					( '0' <= a[i] && a[i] <= '9' ) ) ) {
			if( '0' <= a[i] && a[i] <= '9' ) printf( "%02d:", a[i] - '0' );
			if( 'A' <= a[i] && a[i] <= 'N' ) printf( "%02d:", a[i] - 'A' + 10 );
			break;
		}
	}
	for( i = 0; i < nc && i < nd; ++i ) {
		if( c[i] == d[i] && ( ( 'A' <= c[i] && c[i] <= 'Z' ) ||
				   ( 'a' <= c[i] && c[i] <= 'z' ) ) ) {
			printf( "%02d\n", i );
			break;
		}
	}
	return 0;
}
