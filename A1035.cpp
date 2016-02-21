#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000 + 10;

vector<int> ans;
char name[MAXN][15], pass[MAXN][15];
int n;

bool check( int p ) {
	int len = strlen( pass[p] );
	bool flag = true;
	for( int i = 0; i < len; ++i ) {
		if( pass[p][i] == '1' ) pass[p][i] = '@', flag = false;
		if( pass[p][i] == '0' ) pass[p][i] = '%', flag = false;
		if( pass[p][i] == 'l' ) pass[p][i] = 'L', flag = false;
		if( pass[p][i] == 'O' ) pass[p][i] = 'o', flag = false;
	}
	return flag;
}

int main() {
	scanf( "%d", &n );
	for( int i = 0; i < n; ++i ) {
		scanf( "%s%s", name + i, pass + i );
		if( !check( i ) ) ans.push_back( i );
	}
	if( ans.size() ) {
		printf( "%d\n", ans.size() );
		for( int i = 0; i < ans.size(); ++i ) {
			printf( "%s %s\n", name[ans[i]], pass[ans[i]] );
		}
	} else {
		if( n == 1 ) puts( "There is 1 account and no account is modified" );
		else printf( "There are %d accounts and no account is modified\n", n );
	}
	return 0;
}
