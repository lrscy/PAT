#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
typedef pair<double, int> PDI;

double a[1010];
int n;

int main() {
	int i, m, x;
	double y;
	n = 0;
	scanf( "%d", &m );
	while( m-- ) {
		scanf( "%d%lf", &x, &y );
		a[x] += y;
	}
	scanf( "%d", &m );
	while( m-- ) {
		scanf( "%d%lf", &x, &y );
		a[x] += y;
	}
	for( i = 0; i < 1010; ++i ) {
		if( fabs( a[i] ) >= 1e-2 ) ++n;
	}
	printf( "%d", n );
	for( int i = 1000; i >= 0; --i ) {
		if( fabs( a[i] ) >= 1e-2 )
			printf( " %d %.1f", i, a[i] );
	}
	puts( "" );
	return 0;
}
