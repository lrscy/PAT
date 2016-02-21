#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;
typedef pair<int, int> PII;
const int MAXN = 10000 + 10;
const int MAXM = 100 + 10;

struct Person { int t, tt; };
Person per[MAXN];
priority_queue<PII, vector<PII>, greater<PII> > pq;
int win[MAXM];
int n, k;

bool cmp( const Person &a, const Person &b ) {
	return a.t < b.t;
}

int main() {
	int a, b, c, d, i;
	int sum = 0;
	scanf( "%d%d", &n, &k );
	for( int i = 0; i < n; ++i ) {
		scanf( "%d:%d:%d%d", &a, &b, &c, &d );
		per[i].t = a * 3600 + b * 60 + c;
		per[i].tt = d * 60;
	}
	sort( per, per + n, cmp );
	for( n = n - 1; n >= 0; --n ) if( per[n].t <= 61200 ) break;
	++n;
	if( n == 0 ) { puts( "0.0" ); return 0; }
	memset( win, 0, sizeof( win ) );
	for( i = 0; i < min( n, k ); ++i ) {
		if( per[i].t < 28800 ) { sum += 28800 - per[i].t; per[i].t = 28800; }
		win[i] = per[i].t + per[i].tt;
		pq.push( make_pair( win[i], i ) );
	}
	for( ; i < n && !pq.empty(); ++i ) {
		PII tmp = pq.top(); pq.pop();
		if( per[i].t < 28800 ) { sum += 28800 - per[i].t; per[i].t = 28800; }
		sum += max( tmp.first - per[i].t, 0 );
		win[tmp.second] = max( per[i].t, tmp.first ) + per[i].tt;
		pq.push( make_pair( win[tmp.second], tmp.second ) );
	}
	printf( "%.1f\n", 1.0 * sum / n / 60.0 );
	return 0;
}
