#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int MAXN = 100 + 10;

int n, a;

int main() {
	int tot = 0;
	scanf( "%d", &n );
	int floor = 0;
	for( int i = 0; i < n; ++i ) {
		scanf( "%d", &a );
		if( a == floor ) tot += 5;
		else if( a > floor ) tot += ( a - floor ) * 6 + 5, floor = a;
		else tot += ( floor - a ) * 4 + 5, floor = a;
	}
	printf( "%d\n", tot );
	return 0;
}
