#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
const int MAXN = 2000 + 10;
const double eps = 1e-10;

double a[MAXN], b[15], c[15];
int tb[15], tc[15];
int n, m;

int main() {
	memset( a, 0, sizeof( a ) );
	scanf( "%d", &n );
	for( int i = 0; i < n; ++i ) scanf( "%d%lf", tb + i, b + i );
	scanf( "%d", &m );
	for( int i = 0; i < m; ++i ) scanf( "%d%lf", tc + i, c + i );
	for( int i = 0; i < n; ++i ) {
		for( int j = 0; j < m; ++j )
			a[tb[i] + tc[j]] += b[i] * c[j];
	}
	int tot = 0;
	for( int i = 2000; i >= 0; --i ) if( fabs( a[i] ) > eps ) ++tot;
	printf( "%d", tot );
	for( int i = 2000; i >= 0; --i ) if( fabs( a[i] ) > eps ) printf( " %d %.1f", i, a[i] );
	puts( "" );
	return 0;
}
