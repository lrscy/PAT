#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

double a[MAXN];

int main() {
	int n;
	double ans = 0;
	scanf( "%d", &n );
	for( int i = 0; i < n; ++i ) scanf( "%lf", a + i );
	for( int i = 0; i < n; ++i ) ans += a[i] * ( n - i ) * ( i + 1 );
	printf( "%.2f\n", ans );
	return 0;
}
