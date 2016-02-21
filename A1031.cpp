#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100;

char s[MAXN], space[MAXN];
int n, n1, n2;

int main() {
	int p1, p2;
	scanf( "%s", s );
	n = strlen( s );
	n1 = ( n + 2 ) / 3;
	n2 = n - 2 * n1;
	--n1; p1 = 0; p2 = n - 1;
	for( int i = 0; i < n2; ++i ) space[i] = ' ';
	for( int i = 0; i < n1; ++i ) {
		putchar( s[p1] );
		printf( "%s", space );
		putchar( s[p2] );
		puts( "" );
		++p1; --p2;
	}
	for( int i = p1; i <= p2; ++i ) putchar( s[i] );
	puts( "" );
	return 0;
}
