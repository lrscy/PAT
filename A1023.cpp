#include <bits/stdc++.h>
using namespace std;
const int MAXN = 25;

char a[MAXN];
int num[MAXN], cnt[MAXN];
int n;

int main() {
	scanf( "%s", &a );
	int n = strlen( a );
	for( int i = 0; i < n; ++i ) {
		num[n - 1 - i] = a[i] - '0';
		++cnt[num[n - 1 - i]];
		num[n - 1 - i] *= 2;
	}
	int tmp = 0;
	for( int i = 0; i < n; ++i ) {
		tmp += num[i];
		num[i] = tmp % 10;
		tmp /= 10;
	}
	if( tmp ) num[n++] = tmp;
	for( int i = n - 1; i >= 0; --i ) --cnt[num[i]];
	bool flag = true;
	for( int i = 0; i < 10; ++i ) if( cnt[i] ) { flag = false; break; }
	if( !flag ) puts( "No" );
	else puts( "Yes" );
	for( int i = n - 1; i >= 0; --i ) printf( "%d", num[i] );
	puts( "" );
	return 0;
}
