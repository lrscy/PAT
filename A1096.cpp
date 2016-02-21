#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, nmax = 0, cnt, en, ans;
	scanf( "%d", &n );
	ans = n;
	int a = sqrt( 1.0 * n );
	for( int i = 2; i <= a; ++i ) {
		cnt = 0;
		int tmp = n;
		for( int j = i; j <= i + 13; ++j ) {
			if( tmp % j == 0 ) {
				tmp /= j;
				++cnt;
				en = j;
			} else break;
		}
		if( cnt > nmax ) { nmax = cnt; ans = en; }
	}
	if( nmax == 0 ) nmax = 1;
	printf( "%d\n", nmax );
	ans = ans - nmax + 1;
	for( int i = 0; i < nmax - 1; ++i ) {
		printf( "%d*", ans );
		++ans;
	}
	printf( "%d\n", ans );
	return 0;
}
