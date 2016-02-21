#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 10;

struct Node {
	int x, y, z;
	Node() {}
	Node( int _x, int _y, int _z ) : x( _x ), y( _y ), z( _z ) {}
}que[MAXN];
int dx[10] = { 0, 0, 0, 0, -1, 1 };
int dy[10] = { -1, 0, 1, 0, 0, 0 };
int dz[10] = { 0, 1, 0, -1, 0, 0 };
int a[80][1300][150];
int n, m, p, t, ans;

bool check( int x, int y, int z ) {
	if( 0 <= x && x < p && 0 <= y && y < n && 0 <= z && z < m ) return true;
	return false;
}

int bfs( int x, int y, int z ) {
	int mf, me, ret = 0;
	mf = me = 0; que[me++] = Node( x, y, z );
	a[x][y][z] = 0;
	while( mf != me ) {
		Node u = que[mf++];
		if( mf >= MAXN ) mf -= MAXN;
		++ret;
		for( int i = 0; i < 6; ++i ) {
			int tx = u.x + dx[i];
			int ty = u.y + dy[i];
			int tz = u.z + dz[i];
			if( check( tx, ty, tz ) && a[tx][ty][tz] == 1 ) {
				a[tx][ty][tz] = 0;
				que[me++] = Node( tx, ty, tz );
				if( me >= MAXN ) me -= MAXN;
			}
		}
	}
	return ret >= t ? ret : 0;
}

int main() {
	ans = 0;
	scanf( "%d%d%d%d", &n, &m, &p, &t );
	for( int i = 0; i < p; ++i ) {
		for( int j = 0; j < n; ++j )
			for( int k = 0; k < m; ++k )
				scanf( "%d", &a[i][j][k] );
	}
	for( int i = 0; i < p; ++i ) {
		for( int j = 0; j < n; ++j )
			for( int k = 0; k < m; ++k )
				if( a[i][j][k] == 1 )
					ans += bfs( i, j, k );
	}
	printf( "%d\n", ans );
	return 0;
}
