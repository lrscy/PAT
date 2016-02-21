#include <bits/stdc++.h>
using namespace std;

char n1[15][10] = { "tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };
char n2[15][10] = { "tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };
char str[100];
vector<string> vec;
vector<int> vi;
map<string, int> mp1, mp2;

int main() {
	int n, tt, ta, tb;
	for( int i = 0; i < 13; ++i ) mp1[n1[i]] = i;
	for( int i = 1; i < 13; ++i ) mp2[n2[i]] = i;
	cin >> n; getchar();
	while( n-- ) {
		fgets( str, 100, stdin );
		str[strlen( str ) - 1] = 0;
		if( '0' <= str[0] && str[0] <= '9' ) {
			stringstream ss( str );
			ss >> tt;
			vi.clear();
			if( tt == 0 ) vi.push_back( 0 );
			while( tt ) {
				vi.push_back( tt % 13 );
				tt /= 13;
			}
			if( vi.size() == 1 ) cout << n1[vi[0]] << endl;
			else {
				if( vi[0] ) cout << n2[vi[1]] << " " << n1[vi[0]] << endl;
				else cout << n2[vi[1]] << endl;
			}
		} else {
			int t1, t2, ans = 0;
			stringstream ss( str );
			vec.clear();
			while( ss >> str ) vec.push_back( str );
			if( vec.size() == 1 ) {
				if( mp1.find( vec[0] ) != mp1.end() ) cout << mp1[vec[0]] << endl;
				else if( mp2.find( vec[0] ) != mp2.end() ) cout << mp2[vec[0]] * 13 << endl;
			} else {
				cout << mp2[vec[0]] * 13 + mp1[vec[1]] << endl;
			}
		}
	}
	return 0;
}
