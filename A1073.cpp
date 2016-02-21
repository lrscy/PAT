#include <bits/stdc++.h>
using namespace std;

string a, b, c, ans;
int e;

int main() {
	cin >> a;
	if( a[0] == '-' ) cout << "-";
	int tmp = a.find( 'E' );
	b = a.substr( 1, tmp - 1 );
	c = a.substr( tmp + 2, a.size() - tmp  - 2 );
	stringstream ss( c );
	ss >> e;
	if( e == 0 ) { cout << b << endl; return 0; }
	if( a[tmp + 1] == '+' ) {
		if( e < b.size() - 2 ) ans = b[0] + b.substr( 2, e ) + "." + b.substr( e + 2, b.size() - e - 2 );
		else {
			ans = b[0] + b.substr( 2, b.size() - 2 );
			for( int i = 0; i < e - b.size() + 2; ++i ) ans += "0";
		}
	} else {
		ans = "0.";
		while( --e ) ans += "0";
		ans += b[0] + b.substr( 2, b.size() - 2 );
	}
	cout << ans << endl;
	return 0;
}
