#include <bits/stdc++.h>
using namespace std;
const int INF = 0x7F7F7F7F;
const int MAXN = 1e5 + 10;

vector<int> vec;
int a[MAXN], b[MAXN], c[MAXN];
int n;

int main() {
	scanf( "%d", &n );
	for( int i = 0; i < n; ++i ) scanf( "%d", a + i ); b[0] = a[0]; c[n - 1] = a[n - 1];
	for( int i = 1; i < n; ++i ) b[i] = max( a[i - 1], b[i - 1] );
	for( int i = n - 2; i >= 0; --i ) c[i] = min( a[i + 1], c[i + 1] );
	for( int i = 0; i < n; ++i ) if( b[i] <= a[i] && a[i] <= c[i] ) vec.push_back( a[i] );
	printf( "%d\n", vec.size() );
	sort( vec.begin(), vec.end() );
	for( int i = 0; i < ( int )vec.size() - 1; ++i ) printf( "%d ", vec[i] );
	if( vec.size() ) printf( "%d\n", vec[vec.size() - 1] );
	else puts( "" );
	return 0;
}
