#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int MAXN = 100;

char str[MAXN];
int n, d;

void trans( int &n, int d ) {
	int len = 0;
	while( n ) {
		str[len++] = n % d + '0';
		n /= d;
	}
	n = 0;
	for( int i = 0; i < len; ++i ) {
		n = n * d + str[i] - '0';
	}
	return ;
}

bool isPrime( int n ) {
	if( n < 2 ) return false;
	for( int i = 2; i * i <= n; ++i ) {
		if( n % i == 0 ) return false;
	}
	return true;
}

int main() {
	while( ~scanf( "%d", &n ) && n >= 0 ) {
		scanf( "%d", &d );
		if( !isPrime( n ) ) { puts( "No" ); continue; }
		trans( n, d );
		printf( "%s\n", isPrime( n ) ? "Yes" : "No" );
	}
	return 0;
}
