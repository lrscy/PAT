#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL a, b, c, d;
LL ta, tb, tc, td;

void print( LL x, LL y ) {
	bool flag = false;
	if( x == 0 ) { putchar( '0' ); return ; }
	if( x < 0 ) flag = true;
	if( flag ) printf( "(-" );
	x = abs( x ); y = abs( y );
	LL tmp = __gcd( x, y );
	x /= tmp; y /= tmp;
	tmp = x / y;
	if( tmp ) printf( "%I64d", tmp );
	if( x % y ) printf( "%s%I64d/%I64d", tmp ? " " : "", x % y, y );
	if( flag ) putchar( ')' );
	return ;
}

int main() {
	scanf( "%I64d/%I64d%I64d/%I64d", &a, &b, &c, &d );
	ta = a; tb = b; tc = c; td = d;
	LL tmp = __gcd( b, d );
	tmp = b / tmp * d;
	LL tt;
	tt = tmp / b * a + tmp / d * c;
	print( ta, tb ); printf( " + " );
	print( tc, td ); printf( " = " );
	print( tt, tmp ); puts( "" );
	tt = tmp / b * a - tmp / d * c;
	print( ta, tb ); printf( " - " );
	print( tc, td ); printf( " = " );
	print( tt, tmp ); puts( "" );
	tt = a * c; tmp = b * d;
	LL t = abs( __gcd( tt, tmp ) );
	tt /= t; tmp /= t;
	print( ta, tb ); printf( " * " );
	print( tc, td ); printf( " = " );
	print( tt, tmp ); puts( "" );
	tt = a * d; tmp = b * c;
	if( tmp < 0 ) { tmp *= -1; tt *= -1; }
	print( ta, tb ); printf( " / " );
	print( tc, td ); printf( " = " );
	if( c == 0 ) { puts( "Inf" ); return 0; }
	else print( tt, tmp ); puts( "" );
	return 0;
}
