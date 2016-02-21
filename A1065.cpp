#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL INF = 0x7FFFFFFFFFFFFFFF;
const int MAXN = 30;
const char str[MAXN] = "9223372036854775808";
const char st[MAXN] = "-9223372036854775808";

char a[MAXN], b[MAXN], c[MAXN];
LL na, nb, nc, nd;

int check( LL x ) { return x > 0 ? 1 : x < 0 ? -1 : 0; }

int main() {
	int t, cnt = 0;
	int ta, tb, tc, td;
	bool fa, fb, fc;
	scanf( "%d", &t );
	while( t-- ) {
		printf( "Case #%d: ", ++cnt );
		scanf( "%s%s%s", a, b, c );
		if( !strcmp( a, st ) && !strcmp( b, st ) ) {
			puts( "false" ); continue;
		}
		fa = !strcmp( a, str );
		fb = !strcmp( b, str );
		fc = !strcmp( c, str );
		if( !fa && !fb ) {
			sscanf( a, "%I64d", &na ); ta = check( na );
			sscanf( b, "%I64d", &nb ); tb = check( nb );
			if( !fc ) { sscanf( c, "%I64d", &nc ); tc = check( nc ); }
			nd = na + nb; td = check( nd );
			if( ( ta * tb ) > 0 && ( ta * td ) < 0 ) {
				if( ta > 0 ) puts( "true" );
				else puts( "false" );
			} else {
				if( fc ) puts( "false" );
				else puts( nd > nc ? "true" : "false" );
			}
		} else {
			ta = a[0] == '-' ? -1 : a[0] == '0' ? 0 : 1;
			tb = b[0] == '-' ? -1 : b[0] == '0' ? 0 : 1;
			if( fc ) {
				if( !fa ) { swap( a, b ); swap( ta, tb ); swap( fa, fb ); }
				if( tb <= 0 ) puts( "false" );
				else puts( "true" );
			} else {
				sscanf( c, "%I64d", &nc ); tc = check( nc );
				if( ta ^ tb ) {
					if( !fa ) { swap( a, b ); swap( ta, tb ); swap( fa, fb ); }
					sscanf( b, "%I64d", &nb );
					nd = INF + nb + 1;
					puts( nd > nc ? "true" : "false" );
				} else puts( "true" );
			}
		}
	}
	return 0;
}
