#include <bits/stdc++.h>
using namespace std;
typedef pair<char, int> PII;
const int MAXN = 1e6 + 10;

PII num[MAXN];
int flag[MAXN];
int n, s1, s2;

int main() {
	int a, b, tmp, f = 0;
	char st[2];
	scanf( "%d%d%d", &s1, &s2, &n );
	for( int i = 0; i < n; ++i ) {
		scanf( "%d%s%d", &a, st, &b );
		num[a] = make_pair( st[0], b );
	}
	tmp = s1;
	while( ~tmp ) {
		++flag[tmp];
		tmp = num[tmp].second;
	}
	tmp = s2;
	while( ~tmp ) {
		++flag[tmp];
		if( flag[tmp] > 1 ) { f = 1; break; }
		tmp = num[tmp].second;
	}
	if( f ) printf( "%05d\n", tmp );
	else puts( "-1" );
	return 0;
}
