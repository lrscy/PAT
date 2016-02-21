#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
using namespace std;
const int MAXN = 1000 + 10;

string name[MAXN], be[MAXN], en[MAXN];
int n;

int main() {
	int pa, pb;
	scanf( "%d", &n );
	pa = pb = 0;
	for( int i = 0; i < n; ++i ) {
		cin >> name[i] >> be[i] >> en[i];
		if( be[i] < be[pa] ) pa = i;
		if( en[i] > en[pb] ) pb = i;
	}
	cout << name[pa] << " " << name[pb] << endl;
	return 0;
}
