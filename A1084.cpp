#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100 + 10;

char s1[MAXN], s2[MAXN], s[MAXN];
int n1, n2, n;
int mp[200];

int main() {
	scanf( "%s%s", s1, s2 );
	n1 = n2 = 0;
	while( s1[n1] ) { if( 'a' <= s1[n1] && s1[n1] <= 'z' ) s1[n1] += 'A' - 'a'; ++n1; }
	while( s2[n2] ) { if( 'a' <= s2[n2] && s2[n2] <= 'z' ) s2[n2] += 'A' - 'a'; ++n2; }
	n1 = n2 = 0;
	while( s1[n1] && s2[n2] ) {
		if( s1[n1] != s2[n2] ) {
			if( !mp[s1[n1]] ) s[n++] = s1[n1];
			++mp[s1[n1]];
			++n1;
		} else { ++n1; ++n2; }
	}
	while( s1[n1] ) {
		if( !mp[s1[n1]] ) s[n++] = s1[n1];
		++mp[s1[n1]];
		++n1;
	}
	s[n] = 0;
	printf( "%s\n", s );
	return 0;
}
