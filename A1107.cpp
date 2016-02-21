#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000 + 10;

int fa[MAXN], weight[MAXN];
int n, m;
vector<int> vec;
set<int> s;
set<int>::iterator it;

int mfind( int x ) { return x == fa[x] ? x : fa[x] = mfind( fa[x] ); }

void munion( int u, int v ) {
	int x = mfind( u ), y = mfind( v );
	if( x != y ) {
		fa[y] = x;
		weight[x] += weight[y];
	}
	return ;
}

int main() {
	scanf( "%d", &n );
	for( int i = 0; i < MAXN; ++i ) { fa[i] = i; weight[i] = 0; }
	for( int i = 0; i < n; ++i ) {
		int u, v;
		scanf( "%d: %d", &m, &u );
		s.insert( u );
		for( int j = 1; j < m; ++j ) {
			scanf( "%d", &v );
			munion( u, v );
			s.insert( v );
		}
		fa[u] = mfind( u );
		weight[fa[u]] += 1;
	}
	for( it = s.begin(); it != s.end(); ++it ) fa[*it] = mfind( *it );
	int cnt = 0;
	for( it = s.begin(); it != s.end(); ++it ) {
		if( fa[*it] == *it ) { ++cnt; vec.push_back( weight[*it] ); }
	}
	printf( "%d\n", cnt );
	sort( vec.begin(), vec.end(), greater<int>() );
	cnt = vec.size();
	for( int i = 0; i < cnt - 1; ++i ) printf( "%d ", vec[i] );
	printf( "%d\n", vec[cnt - 1] );
	return 0;
}
