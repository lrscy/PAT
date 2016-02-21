#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000 + 10;

char s1[MAXN], s2[MAXN];
int d1[200], d2[200];
int n1, n2;

int main() {
	bool flag = true;
	int cnt = 0, cc = 0;
	scanf( "%s%s", s1, s2 );
	n1 = n2 = 0;
	while( s1[n1] ) { ++d1[s1[n1]]; ++n1; }
	while( s2[n2] ) { ++d2[s2[n2]]; ++n2; }
	for( int i = 0; i < 200; ++i ) {
		if( d2[i] > d1[i] ) { flag = false; cc += d1[i] - d2[i]; }
		else cnt += d1[i] - d2[i];
	}
	if( flag ) printf( "Yes %d\n", cnt );
	else printf( "No %d\n", -cc );
	return 0;
}
