#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int MAXN = 100 + 10;

char out[15][10] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
char str[MAXN];

int main() {
	scanf( "%s", str );
	int len = strlen( str );
	int sum = 0;
	for( int i = 0; i < len; ++i ) sum += str[i] - '0';
	len = 0;
	while( sum ) {
		str[len++] = sum % 10 + '0';
		sum /= 10;
	}
	for( int i = len - 1; i > 0; --i ) printf( "%s ", out[str[i] - '0'] );
	printf( "%s\n", out[str[0] - '0'] );
	return 0;
}
