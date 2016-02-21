#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const int MAXN = 1e5 + 10;

vector<int> g[MAXN];
double p, r;
double b[MAXN];
int a[MAXN], que[MAXN];
int n;

int main() {
	int root, mf, me;
	scanf( "%d%lf%lf", &n, &p, &r );
	p *= -1;
	for( int i = 0; i < n; ++i ) {
		scanf( "%d", a + i );
		if( a[i] == -1 ) root = i;
		else g[a[i]].push_back( i );
	}
	mf = me = 0;
	b[root] = p; que[me++] = root;
	while( mf != me ) {
		int u = que[mf++];
		if( mf >= MAXN ) mf -= MAXN;
		for( int i = 0; i < g[u].size(); ++i ) {
			int v = g[u][i];
			if( b[v] - b[u] * ( 1 + r / 100 ) > eps ) {
				b[v] = b[u] * ( 1 + r / 100 );
				que[me++] = v;
			}
			if( me >= MAXN ) me -= MAXN;
		}
	}
	double nmin = 0;
	int cnt = 0;
	for( int i = 0; i < n; ++i ) if( !g[i].size() ) {
		if( b[i] - nmin < -eps ) {
			nmin = b[i];
			cnt = 1;
		} else if( b[i] - nmin <= eps ) {
			++cnt;
		}
	}
	printf( "%.2f %d\n", -nmin, cnt );
	return 0;
}
