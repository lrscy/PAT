#include <bits/stdc++.h>
using namespace std;

char aa[3], bb[3], cc[3];
int a, b, c;

int main() {
	scanf( "%d%d%d", &a, &b, &c );
	aa[0] = aa[1] = bb[0] = bb[1] = cc[0] = cc[1] = '0';
	int tmp = 1;
	while( a ) {
		aa[tmp] = a % 13;
		if( aa[tmp] < 10 ) aa[tmp] += '0';
		else aa[tmp] += 'A' - 10;
		a /= 13; --tmp;
	}
	tmp = 1;
	while( b ) {
		bb[tmp] = b % 13;
		if( bb[tmp] < 10 ) bb[tmp] += '0';
		else bb[tmp] += 'A' - 10;
		b /= 13; --tmp;
	}
	tmp = 1;
	while( c ) {
		cc[tmp] = c % 13;
		if( cc[tmp] < 10 ) cc[tmp] += '0';
		else cc[tmp] += 'A' - 10;
		c /= 13; --tmp;
	}
	printf( "#%s%s%s\n", aa, bb, cc );
	return 0;
}
