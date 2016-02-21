#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>
using namespace std;
const int MAXN = 2000 + 10;
const double eps = 1e-8;

struct Person {
	char name[10];
	double a, c, m, e;
};
Person per[MAXN];
map<string, int> mp;
int n, m;

int main() {
	char str[10];
	scanf( "%d%d", &n, &m );
	for( int i = 0; i < n; ++i ) {
		scanf( "%s%lf%lf%lf", per[i].name, &per[i].c, &per[i].m, &per[i].e );
		per[i].a = ( per[i].c + per[i].m + per[i].e ) / 3;
		mp[per[i].name] = i + 1;
	}
	while( m-- ) {
		scanf( "%s", str );
		if( !mp[str] ) { puts( "N/A" ); continue; }
		int r = MAXN, cnt, pos = mp[str] - 1; char c;
		cnt = 1;
		for( int i = 0; i < n; ++i ) if( per[i].a - per[pos].a > eps ) ++cnt;
		if( cnt < r ) { r = cnt; c = 'A'; }
		cnt = 1;
		for( int i = 0; i < n; ++i ) if( per[i].c - per[pos].c > eps ) ++cnt;
		if( cnt < r ) { r = cnt; c = 'C'; }
		cnt = 1;
		for( int i = 0; i < n; ++i ) if( per[i].m - per[pos].m > eps ) ++cnt;
		if( cnt < r ) { r = cnt; c = 'M'; }
		cnt = 1;
		for( int i = 0; i < n; ++i ) if( per[i].e - per[pos].e > eps ) ++cnt;
		if( cnt < r ) { r = cnt; c = 'E'; }
		printf( "%d %c\n", r, c );
	}
	return 0;
}
