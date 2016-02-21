#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int a[1000], len;

bool check( int n, int r ) {
	if( n == 0 ) return true;
	len = 0;
	while( n ) {
		a[len++] = n % r;
		n /= r;
	}
	for( int i = 0; i < len / 2; ++i ) {
		if( a[i] != a[len - 1 - i] ) return false;
	}
	return true;
}

int main() {
	int n, k;
	scanf( "%d%d", &n, &k );
	if( check( n, k ) ) puts( "Yes" );
	else puts( "No" );
	for( int i = len - 1; i > 0; --i ) printf( "%d ", a[i] );
	printf( "%d\n", a[0] );
	return 0;
}
