#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<int> vec;
LL nmax;
int n, p, k;

LL mpow( LL a, int b ) {
	LL ret = 1;
	while( b ) {
		if( b & 1 ) ret *= a;
		a *= a;
		b >>= 1;
	}
	return ret;
}

void dfs( LL res, int cur, vector<int> &v ) {
	if( cur == k ) {
		if( res == 0 ) {
			int sum = 0;
			for( int i = 0; i < v.size(); ++i ) sum += v[i];
			if( sum >= nmax ) {
				vec = v;
				nmax = sum;
			}
		}
		return ;
	}
	int high = sqrt( 1.0 * res );
	int low = cur ? v[cur - 1] : 1;
	for( int i = low; i <= high; ++i ) {
		LL tmp = mpow( i, p );
		if( res >= tmp ) {
			v[cur] = i;
			dfs( res - tmp, cur + 1, v );
		} else return ;
	}
	return ;
}

int main() {
	nmax = 0;
	scanf( "%d%d%d", &n, &k, &p );
	vector<int> v( k );
	dfs( n, 0, v );
	reverse( vec.begin(), vec.end() );
	if( vec.size() == k ) {
		printf( "%d = ", n );
		printf( "%d^%d", vec[0], p );
		for( int i = 1; i < vec.size(); ++i ) {
			printf( " + %d^%d", vec[i], p );
		}
	} else printf( "Impossible" );
	puts( "" );
	return 0;
}
