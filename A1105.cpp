#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10000 + 10;
const int MAXM = 1000 + 10;

int a[MAXN], dx[5] = { 0, 1, 0, -1 }, dy[5] = { 1, 0, -1, 0 };
int ans[MAXM][MAXM];
int N, n, m, cnt, dcnt;

bool check( int x, int y ) {
	if( 1 <= x && x <= n && 1 <= y && y <= m ) return true;
	return false;
}

int main() {
	int x, y;
	scanf( "%d", &N );
	for( int i = 0; i < N; ++i ) scanf( "%d", a + i );
	sort( a, a + N, greater<int>() );
	for( int i = ( int )sqrt( N ); i; --i ) {
		if( N % i == 0 ) { m = i; n = N / i; break; }
	}
	dcnt = cnt = 0; x = y = 1;
	for( int i = 0; i < N; ++i ) {
		ans[x][y] = a[cnt++];
		int tx = x + dx[dcnt], ty = y + dy[dcnt];
		if( check( tx, ty ) && !ans[tx][ty] ) { x = tx; y = ty; }
		else {
			dcnt = ( dcnt + 1 ) % 4;
			x += dx[dcnt]; y += dy[dcnt];
		}
	}
	for( int i = 1; i <= n; ++i ) {
		for( int j = 1; j < m; ++j )
			printf( "%d ", ans[i][j] );
		printf( "%d\n", ans[i][m] );
	}
	return 0;
}
