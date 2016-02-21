#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10000 + 10;

struct Book {
	int nkey;
	string id, title, author, keyword[10], publisher, year;
};
Book book[MAXN];
int n;
vector<string> ans;

int main() {
	ios::sync_with_stdio( false );
	int m, k;
	char tmp[MAXN];
	string tstr;
	scanf( "%d", &n ); getchar();
	for( int i = 0; i < n; ++i ) {
		fgets( tmp, MAXN, stdin ); tmp[strlen( tmp ) - 1] = 0;
		book[i].id = tmp;
		fgets( tmp, MAXN, stdin ); tmp[strlen( tmp ) - 1] = 0;
		book[i].title = tmp;
		fgets( tmp, MAXN, stdin ); tmp[strlen( tmp ) - 1] = 0;
		book[i].author = tmp;
		fgets( tmp, MAXN, stdin ); tmp[strlen( tmp ) - 1] = 0;
		stringstream ss( tmp ); book[i].nkey = 0;
		while( ss >> book[i].keyword[book[i].nkey] ) ++book[i].nkey;
		fgets( tmp, MAXN, stdin ); tmp[strlen( tmp ) - 1] = 0;
		book[i].publisher = tmp;
		fgets( tmp, MAXN, stdin ); tmp[strlen( tmp ) - 1] = 0;
		book[i].year = tmp;
	}
	scanf( "%d", &m );
	while( m-- ) {
		ans.clear();
		scanf( "%d: ", &k );
		fgets( tmp, MAXN, stdin ); tmp[strlen( tmp ) - 1] = 0;
		printf( "%d: %s\n", k, tmp );
		tstr = tmp;
		switch( k ) {
			case 1:
				for( int i = 0; i < n; ++i ) if( tmp == book[i].title ) ans.push_back( book[i].id );
				break;
			case 2:
				for( int i = 0; i < n; ++i ) if( tmp == book[i].author ) ans.push_back( book[i].id );
				break;
			case 3:
				for( int i = 0; i < n; ++i ) {
					for( int j = 0; j < book[i].nkey; ++j ) {
						if( tmp == book[i].keyword[j] ) {
							ans.push_back( book[i].id );
							break;
						}
					}
				}
				break;
			case 4:
				for( int i = 0; i < n; ++i ) if( tmp == book[i].publisher ) ans.push_back( book[i].id );
				break;
			case 5:
				for( int i = 0; i < n; ++i ) if( tmp == book[i].year ) ans.push_back( book[i].id );
				break;
		}
		sort( ans.begin(), ans.end() );
		for( int i = 0; i < ans.size(); ++i ) printf( "%s\n", ans[i].c_str() );
		if( ans.size() == 0 ) puts( "Not Found" );
	}
	return 0;
}
