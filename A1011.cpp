#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
const double eps = 1e-8;

int main() {
	double a, b, c, dmax, ans = 1.;
	scanf( "%lf%lf%lf", &a, &b, &c );
	dmax = max( a, max( b, c ) ); ans *= dmax;
	if( fabs( dmax - a ) < eps ) printf( "W " );
	else if( fabs( dmax - b ) < eps ) printf( "T " );
	else if( fabs( dmax - c ) < eps ) printf( "L " );
	scanf( "%lf%lf%lf", &a, &b, &c );
	dmax = max( a, max( b, c ) ); ans *= dmax;
	if( fabs( dmax - a ) < eps ) printf( "W " );
	else if( fabs( dmax - b ) < eps ) printf( "T " );
	else if( fabs( dmax - c ) < eps ) printf( "L " );
	scanf( "%lf%lf%lf", &a, &b, &c );
	dmax = max( a, max( b, c ) ); ans *= dmax;
	if( fabs( dmax - a ) < eps ) printf( "W " );
	else if( fabs( dmax - b ) < eps ) printf( "T " );
	else if( fabs( dmax - c ) < eps ) printf( "L " );
	printf( "%.2f\n", 2 * ( ans * 0.65 - 1 ) );
	return 0;
}
