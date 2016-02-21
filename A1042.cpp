#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100 + 10;

int num[MAXN], ans[2][MAXN];
int n;

void print( int x ) {
	switch( ( x - 1 ) / 13 ) {
		case 0: putchar( 'S' ); break;
		case 1: putchar( 'H' ); break;
		case 2: putchar( 'C' ); break;
		case 3: putchar( 'D' ); break;
		default: putchar( 'J' );
	}
	printf( "%d", ( x - 1 ) % 13 + 1 );
	return ;
}

int main() {
	int p = 0;
	scanf( "%d", &n );
	for( int i = 0; i < 54; ++i ) { scanf( "%d", num + i ); ans[p][i] = i + 1; }
	for( int i = 0; i < n; ++i ) {
		for( int j = 0; j < 54; ++j ) ans[!p][num[j] - 1] = ans[p][j];
		p ^= 1;
	}
	for( int i = 0; i < 53; ++i ) { print( ans[p][i] ); putchar( ' ' ); }
	print( ans[p][53] ); puts( "" );
	return 0;
}
