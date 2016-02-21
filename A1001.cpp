#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int main() {
	int a, b;
	char st[20];
	scanf( "%d%d", &a, &b );
	a = a + b;
	if( a == 0 ) {
		puts( "0" );
		return 0;
	}
	if( a < 0 ) putchar( '-' );
	int len = 0, tmp = 0;
   	a = a < 0 ? -a : a;
	while( a ) {
		st[len++] = a % 10 + '0';
		a /= 10;
		++tmp;
		if( tmp % 3 == 0 ) st[len++] = ',';
	}
	if( st[len - 1] == ',' ) --len;
	while( len-- ) putchar( st[len] );
	puts( "" );
	return 0;
}
