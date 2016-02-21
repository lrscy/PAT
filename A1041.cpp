#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10000 + 10;
const int MAXM = 100000 + 10;

int num[MAXN], a[MAXM];
int n;

int main() {
	scanf( "%d", &n );
	for( int i = 0; i < n; ++i ) {
		scanf( "%d", a + i );
		++num[a[i]];
	}
	bool flag = false;
	for( int i = 0; i < n; ++i ) {
		if( num[a[i]] == 1 ) {
			printf( "%d\n", a[i] );
			flag = true;
		   	break;
		}
	}
	if( !flag ) puts( "None" );
	return 0;
}
