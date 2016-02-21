#include <bits/stdc++.h>
using namespace std;

int a1, b1, c1, a2, b2, c2;

int main() {
	int tmp = 0;
	scanf( "%d.%d.%d%d.%d.%d", &a1, &b1, &c1, &a2, &b2, &c2 );
	tmp = c1 + c2; c1 = tmp % 29; tmp /= 29;
	tmp += b1 + b2; b1 = tmp % 17; tmp /= 17;
	tmp += a1 + a2; a1 = tmp;
	printf( "%d.%d.%d\n", a1, b1, c1 );
	return 0;
}
