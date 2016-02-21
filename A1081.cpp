#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 100 + 10;

LL a[MAXN], b[MAXN];
LL aa, ab, an;
int n;

int main() {
	scanf( "%d", &n );
	scanf( "%I64d/%I64d", a, b );
	aa = a[0]; ab = b[0]; an = 0;
	for( int i = 1; i < n; ++i ) {
		scanf( "%I64d/%I64d", a + i, b + i );
		LL tmp = __gcd( ab, b[i] );
		tmp = ab / tmp * b[i];
		aa = tmp / ab * aa + tmp / b[i] * a[i];
		ab = tmp;
		tmp = abs( __gcd( aa, ab ) );
		aa /= tmp; ab /= tmp;
		if( ab == 1 ) { an += aa; aa = 0; }
		an += aa / ab;
		aa %= ab;
	}
	if( an == 0 && aa == 0 ) { puts( "0" ); return 0; }
	if( an < 0 || ( an == 0 && aa < 0 ) ) { putchar( '-' ); an *= -1; }
	if( an ) printf( "%I64d", an );
	if( ab != 1 ) printf( "%s%I64d/%I64d", an ? " " : "", abs( aa ), ab );
	puts( "" );
	return 0;
}
