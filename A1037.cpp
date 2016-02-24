#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x7F7F7F7F;
const int MAXN = 1e5 + 10;

int a[MAXN], b[MAXN];
int na, nb;

int main() {
	scanf( "%d", &na );
	for( int i = 0; i < na; ++i ) scanf( "%d", a + i );
	scanf( "%d", &nb );
	for( int i = 0; i < nb; ++i ) scanf( "%d", b + i );
	sort( a, a + na ); sort( b, b + nb );
	int p1, p2, p3, p4, t1, t2;
	LL ans = 0;
	p1 = p3 = 0; p2 = na - 1; p4 = nb - 1;
	while( p1 <= p2 && p3 <= p4 ) {
		LL tans = -INF;
		if( tans < a[p1] * b[p3] ) { tans = a[p1] * b[p3]; t1 = p1; t2 = p3; }
		if( tans < a[p2] * b[p4] ) { tans = a[p2] * b[p4]; t1 = p2; t2 = p4; }
		if( tans < a[p1] * b[p4] ) { tans = a[p1] * b[p4]; t1 = p1; t2 = p4; }
		if( tans < a[p2] * b[p3] ) { tans = a[p2] * b[p3]; t1 = p2; t2 = p3; }
		if( t1 == p1 ) ++p1; else --p2;
		if( t2 == p3 ) ++p3; else --p4;
		if( tans > 0 ) ans += tans;
		else break;
	}
	printf( "%I64d\n", ans );
	return 0;
}
