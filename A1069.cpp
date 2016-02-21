#include <bits/stdc++.h>
using namespace std;

char ca[5], cb[5], cc[5];
int a, b, c;

int main() {
	bool flag = true;
	scanf( "%d", &a );
	sprintf( ca, "%04d", a );
	for( int i = 1; i < 4; ++i ) if( ca[i] != ca[0] ) { flag = false; break; }
	if( flag ) { printf( "%s - %s = 0000\n", ca, ca ); return 0; }
	while( true ) {
		strcpy( cb, ca ); strcpy( cc, ca );
		sort( cb, cb + 4, greater<char>() ); sort( cc, cc + 4 );
		sscanf( cb, "%d", &b ); sscanf( cc, "%d", &c );
		sscanf( ca, "%d", &a );
		printf( "%04d - %04d = %04d\n", b, c, b - c );
		if( b - c == 6174 ) break;
		sprintf( ca, "%04d", b - c );
	}
	return 0;
}
