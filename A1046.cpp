#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200000 + 10;

int d[MAXN], s[MAXN];
int n, m;

int main() {
	int a, b;
	scanf( "%d", &n );
	s[0] = 0;
	for( int i = 1; i <= n; ++i ) { scanf( "%d", d + i ); d[i + n] = d[i]; }
	for( int i = 1; i <= 2 * n; ++i ) s[i] = s[i - 1] + d[i];
	scanf( "%d", &m );
	while( m-- ) {
		scanf( "%d%d", &a, &b );
		if( a > b ) swap( a, b );
		int ans = min( s[b - 1] - s[a - 1], s[a + n - 1] - s[b - 1] );
		printf( "%d\n", ans );
	}
	return 0;
}
