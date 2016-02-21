#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10000 + 10;

char a[MAXN], b[MAXN], c[MAXN];
bool ab[150];

int main() {
    int na, nb, nc; nc = 0;
    fgets( a, MAXN, stdin ); na = strlen( a );
    fgets( b, MAXN, stdin ); nb = strlen( b );
    for( int i = 0; i < nb; ++i ) ab[b[i]] = true;
    for( int i = 0; i < na; ++i ) if( !ab[a[i]] ) c[nc++] = a[i];
    c[nc] = 0;
    printf( "%s\n", c );
    return 0;
}
