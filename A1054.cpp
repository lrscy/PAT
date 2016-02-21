#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000 + 10;

map<int, int> mp;
int c[MAXN][MAXN];
int n, m, cnt, ans;

int main() {
	cnt = 0;
	scanf( "%d%d", &n, &m );
	for( int i = 0; i < n; ++i ) {
		for( int j = 0; j < m; ++j ) {
			scanf( "%d", &c[i][j] );
			++mp[c[i][j]];
			if( mp[c[i][j]] > cnt ) {
				ans = c[i][j];
				cnt = mp[c[i][j]];
			}
		}
	}
	printf( "%d\n", ans );
	return 0;
}
