#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e4 + 10;

struct Node {
	string a, b, c;
	bool operator < ( const Node &tmp ) const {
		return b < tmp.b;
	}
}node[MAXN];
vector<string> vec;
string ti[MAXN];
map<string, int> mp;
map<string, int>::iterator it;
int num[MAXN];
int n, m, nmax;

bool cmp( const Node &a, const Node &b ) {
	return a.a == b.a ? a.b < b.b : a.a < b.a;
}

int cal( int i, int j ) {
	int ret = 0;
	int hh, mm, ss;
	hh = ( node[i].b[0] - '0' ) * 10 + ( node[i].b[1] - '0' );
	mm = ( node[i].b[3] - '0' ) * 10 + ( node[i].b[4] - '0' );
	ss = ( node[i].b[6] - '0' ) * 10 + ( node[i].b[7] - '0' );
	ret = hh * 3600 + mm * 60 + ss;
	hh = ( node[j].b[0] - '0' ) * 10 + ( node[j].b[1] - '0' );
	mm = ( node[j].b[3] - '0' ) * 10 + ( node[j].b[4] - '0' );
	ss = ( node[j].b[6] - '0' ) * 10 + ( node[j].b[7] - '0' );
	ret = hh * 3600 + mm * 60 + ss - ret;
	return ret;
}

int main() {
	string str;
	int tn;
	nmax = 0;
	cin >> n >> m;
	for( int i = 0; i < n; ++i ) cin >> node[i].a >> node[i].b >> node[i].c;
	sort( node, node + n, cmp );
	tn = 0;
	for( int i = 0; i < n; ++i ) {
		if( node[i].c == "in" ) {
			if( i == n - 1 ) continue;
			if( tn && node[tn - 1].c == "in" ) --tn;
			node[tn++] = node[i];
		} else {
			if( tn == 0 || node[tn - 1].c == "out" ) continue;
			if( node[tn - 1].a != node[i].a ) { --tn; continue; }
			node[tn++] = node[i];
		}
	}
	if( node[tn - 1].c == "in" ) --tn;
	n = tn;
	for( int i = 0; i < n; i += 2 ) mp[node[i].a] += cal( i, i + 1 );
	for( it = mp.begin(); it != mp.end(); ++it ) {
		if( it->second > nmax ) { nmax = it->second; vec.clear(); vec.push_back( it->first ); }
		else if( it->second == nmax ) vec.push_back( it->first );
	}
	sort( vec.begin(), vec.end() );
	sort( node, node + n );
	int cnt = 0; tn = 0;
	for( int i = 0; i < n; ++i ) {
		ti[tn++] = node[i].b;
		if( node[i].c == "in" ) ++cnt;
		else --cnt;
		num[i] = cnt;
	}
	while( m-- ) {
		cin >> str;
		int x = upper_bound( ti, ti + tn, str ) - ti - 1;
		if( x == -1 ) { puts( "0" ); continue; }
		printf( "%d\n", num[x] );
	}
	cout << vec[0] << " ";
	for( int i = 1; i < vec.size(); ++i ) cout << vec[i] << " ";
	printf( "%02d:%02d:%02d\n", nmax / 3600, ( nmax % 3600 ) / 60, nmax % 60 );
	return 0;
}
