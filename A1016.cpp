#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
using namespace std;
const int MAXN = 1000 + 10;

struct Person {
	char name[25];
	int m, dd, hh, mm;
	char status[20];
};
Person per[MAXN], tmp[MAXN];
double cost[30], tsum;
int n, cnt;

bool cmp( const Person &a, const Person &b ) {
	string s1( a.name ), s2( b.name );
	if( s1 != s2 ) return s1 < s2;
	else if( a.m != b.m ) return a.m < b.m;
	else if( a.dd != b.dd ) return a.dd < b.dd;
	else if( a.hh != b.hh ) return a.hh < b.hh;
	else if( a.mm != b.mm ) return a.mm < b.mm;
	return false;
}

double cal( int a, int b, int &tt ) {
	double ret = 0;
	int t1 = tmp[a].dd * 24 * 60 + tmp[a].hh * 60 + tmp[a].mm;
	int t2 = tmp[b].dd * 24 * 60 + tmp[b].hh * 60 + tmp[b].mm;
	tt = t2 - t1;
	if( tmp[a].dd == tmp[b].dd && tmp[a].hh == tmp[b].hh ) return cost[tmp[a].hh] * ( tmp[b].mm - tmp[a].mm );
	ret += ( 60 - tmp[a].mm ) * cost[tmp[a].hh] + tmp[b].mm * cost[tmp[b].hh];
	++tmp[a].hh; if( tmp[a].hh == 24 ) { tmp[a].hh = 0; ++tmp[a].dd; }
	if( tmp[a].dd == tmp[b].dd ) {
		for( int i = tmp[a].hh; i < tmp[b].hh; ++i ) ret += 60 * cost[i];
	} else {
		for( int i = tmp[a].hh; i < 24; ++i ) ret += 60 * cost[i];
		++tmp[a].dd;
		for( int i = 0; i < tmp[b].hh; ++i ) ret += 60 * cost[i];
		ret += tsum * ( tmp[b].dd - tmp[a].dd );
	}
	return ret;
}

int main() {
	char str[25];
	memset( per, 0, sizeof( per ) );
	tsum = 0;
	for( int i = 0; i < 24; ++i ) { scanf( "%lf", cost + i ); cost[i] *= 0.01; tsum += 60 * cost[i]; }
	scanf( "%d", &n );
	for( int i = 0; i < n; ++i ) {
		scanf( "%s%d:%d:%d:%d%s", per[i].name, &per[i].m, &per[i].dd, &per[i].hh, &per[i].mm, per[i].status );
	}
	sort( per, per + n, cmp );
	int ncnt = 0; bool flag = true;
	for( int i = 0; i < n; ++i ) {
		if( flag == true && per[i].status[1] == 'f' ) continue;
		if( flag == true && per[i].status[1] == 'n' && per[i + 1].status[1] != 'f' ) continue;
		flag = !flag;
		tmp[ncnt++] = per[i];
	}
	if( ncnt == 0 ) return 0;
	strcpy( str, tmp[0].name );
	double tot = 0;
	printf( "%s %02d\n", tmp[0].name, tmp[0].m );
	for( int i = 0; i < ncnt; i += 2 ) {
		if( strcmp( str, tmp[i].name ) ) {
			if( i ) {
				printf( "Total amount: $%.2f\n", tot );
				printf( "%s %02d\n", tmp[i].name, tmp[i].m );
				strcpy( str, tmp[i].name );
			}
			tot = 0;
		}
		int tt;
		printf( "%02d:%02d:%02d %02d:%02d:%02d ", tmp[i].dd, tmp[i].hh, tmp[i].mm, tmp[i + 1].dd, tmp[i + 1].hh, tmp[i + 1].mm );
		double td = cal( i, i + 1, tt );
		printf( "%d $%.2f\n", tt, td );
		tot += td;
	}
	printf( "Total amount: $%.2f\n", tot );
	return 0;
}
