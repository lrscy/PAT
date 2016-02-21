#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3F3F3F3F;

char str[100][300], ans[300];
int n;

int main() {
	int tmp = INF, cnt = 0;
	scanf( "%d", &n ); getchar();
	for( int i = 0; i < n; ++i ) {
		fgets( str[i], 300, stdin );
		str[i][strlen( str[i] ) - 1] = 0;
		tmp = min( tmp, ( int )strlen( str[i] ) );
		reverse( str[i], str[i] + strlen( str[i] ) );
	}
	for( int i = 0; i <= tmp; ++i ) {
		bool flag = true;
		for( int j = 1; j < n; ++j ) {
			if( str[j][i] != str[0][i] ) {
				flag = false;
				break;
			}
		}
		if( !flag ) break;
		ans[cnt++] = str[0][i];
	}
	ans[cnt] = 0;
	if( cnt > 1 && ans[cnt - 1] == 0 ) --cnt;
	if( !cnt ) puts( "nai" );
	else {
		reverse( ans, ans + cnt );
		ans[cnt] = 0;
		printf( "%s\n", ans );
	}
	return 0;
}
