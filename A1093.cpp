#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
const int MOD = 1e9 + 7;

char st[MAXN];
int num[MAXN];

int main() {
	int len, cnt;
	memset( num, 0, sizeof( num ) );
	scanf( "%s", st );
	len = strlen( st );
	cnt = 0;
	for( int i = len - 1; i >= 0; --i ) {
		if( st[i] == 'T' ) ++cnt;
		if( st[i] == 'A' ) num[i] = cnt;
	}
	cnt = 0;
	for( int i = len - 1; i >= 0; --i ) {
		if( st[i] == 'A' ) cnt = ( 1LL * cnt + num[i] ) % MOD;
		if( st[i] == 'P' ) num[i] = cnt;
	}
	cnt = 0;
	for( int i = len - 1; i >= 0; --i ) {
		if( st[i] == 'P' ) cnt = ( 1LL * cnt + num[i] ) % MOD;
	}
	printf( "%d\n", cnt );
	return 0;
}
