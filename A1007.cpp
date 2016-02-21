#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int MAXN = 10000 + 10;

int a[MAXN];
int n;

int main() {
	long long sum, nmax;
	bool flag = false;
	scanf( "%d", &n );
	for( int i = 0; i < n; ++i ) {
		scanf( "%d", a + i );
		if( a[i] >= 0 ) flag = true;
	}
	if( !flag ) { printf( "0 %d %d\n", a[0], a[n - 1] ); return 0; }
	sum = 0;
	int be, st, en; be = 0; sum = 0; nmax = -1;
	for( int i = 0; i < n; ++i ) {
		sum += a[i];
		if( sum < 0 ) { sum = 0; be = i + 1; }
		else {
			if( sum > nmax ) {
				nmax = sum;
				st = be; en = i;
			}
		}
	}
	printf( "%lld %d %d\n", nmax, a[st], a[en] );
	return 0;
}
