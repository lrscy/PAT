#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 2e6 + 10;

LL a[MAXN];
int n;

int main() {
	int cnt = 0;
	scanf( "%d", &n );
	for( int i = 0; i < n; ++i ) scanf( "%I64d", a + cnt ), ++cnt;
	scanf( "%d", &n );
	for( int i = 0; i < n; ++i ) scanf( "%I64d", a + cnt ), ++cnt;
	sort( a, a + cnt );
	printf( "%I64d\n", a[( cnt - 1 ) / 2] );
	return 0;
}
