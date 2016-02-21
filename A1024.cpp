#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100 + 10;

char a[MAXN], b[MAXN];
int k, len;

bool check() {
	bool flag = true;
	for( int i = 0; i < len / 2; ++i ) {
		if( a[i] != a[len - i - 1] ) return false;
	}
	return true;
}

void add() {
	int cnt = 0;
	reverse( a, a + len ); reverse( b, b + len );
	for( int i = 0; i < len; ++i ) {
		int tmp = a[i] - '0' + b[i] - '0' + cnt;
		a[i] = tmp % 10 + '0';
		cnt = tmp / 10;
	}
	if( cnt ) a[len++] = cnt + '0';
	reverse( a, a + len );
	return ;
}

int main() {
	int t = 0;
	scanf( "%s%d", a, &k );
	len = strlen( a );
	while( !check() && k-- ) {
		++t;
		strcpy( b, a );
		reverse( b, b + len );
		add();
	}
	printf( "%s\n%d\n", a, t );
	return 0;
}
