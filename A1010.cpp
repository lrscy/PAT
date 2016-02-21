#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

char a[15], b[15];
int tag, radix;

void mswitch( char *str, int radix, int to ) {
	long long tmp = 0;
	int len = strlen( str );
	for( int i = 0; i < len; ++i ) {
		tmp = tmp * radix;
		if( '0' <= str[i] && str[i] <= '9' ) tmp += str[i] - '0';
		else if( 'a' <= str[i] && str[i] <= 'z' ) tmp += 10 + str[i] - 'a';
	}
	len = 0;
	while( tmp ) {
		int tt = tmp % to;
		if( 0 <= tt && tt <= 9 ) str[len++] = tt + '0';
		else if( 10 <= tt && tt <= 35 ) str[len++] = tt - 10 + 'a';
		tmp /= to;
	}
	for( int i = 0; i < len / 2; ++i ) { 
		char t = str[i];
	   	str[i] = str[len - i - 1]; 
		str[len - i - 1] = t;
   	}
	return ;
}

int main() {
	scanf( "%s%s%d%d", a, b, &tag, &radix );
	if( radix == 0 ) { puts( "Impossible" ); return 0; }
	if( radix == 1 ) {
		if( strcmp( a, b ) ) puts( "Impossible" );
		else puts( "1" );
		return 0;
	}
	bool flag = false;
	if( tag == 1 ) {
		for( int i = 2; i <= 36; ++i ) {
			mswitch( a, radix, i );
			if( !strcmp( a, b ) ) {
				printf( "%d\n", i );
				flag = true;
				break;
			}
		}
		if( !flag ) puts( "Impossible" );
	} else {
		for( int i = 2; i <= 36; ++i ) {
			mswitch( b, radix, i );
			if( !strcmp( a, b ) ) {
				printf( "%d\n", i );
				flag = true;
				break;
			}
		}
		if( !flag ) puts( "Impossible" );
	}
	return 0;
}
