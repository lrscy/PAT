#include <bits/stdc++.h>
using namespace std;
const double INF = 0x7F7F7F7F7F7F7F7F;
const double eps = 1e-8;
const int MAXN = 1e5 + 10;

vector<int> g[MAXN];
double d[MAXN];
double p, r;
int n, k;

void dfs( int u ) {
	for( int i = 0; i < g[u].size(); ++i ) {
		int v = g[u][i];
		if( d[u] * ( 1.0 + r / 100 ) - d[v] < -eps ) {
			d[v] = d[u] * ( 1.0 + r / 100 );
			dfs( v );
		}
	}
	return ;
}

int main() {
	int x;
	scanf( "%d%lf%lf", &n, &p, &r );
	for( int i = 0; i < n; ++i ) d[i] = INF;
	d[0] = p;
	for( int i = 0; i < n; ++i ) {
		scanf( "%d", &k );
		for( int j = 0; j < k; ++j ) {
			scanf( "%d", &x );
			g[i].push_back( x );
		}
	}
	dfs( 0 );
	double ans = INF;
	int cnt = 0;
	for( int i = 0; i < n; ++i ) {
		if( g[i].size() == 0 ) {
			if( d[i] - ans <= -eps ) { ans = d[i]; cnt = 1; }
			else if( d[i] - ans < eps ) ++cnt;
		}
	}
	printf( "%.4f %d\n", ans, cnt );
	return 0;
}
