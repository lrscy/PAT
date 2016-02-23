#include <bits/stdc++.h>
using namespace std;
typedef pair<double, double> PDD;
const double eps = 1e-8;
const int INF = 0x7F7F7F7F;
const int MAXN = 1e4 + 10;

PDD s[MAXN];
double c, dis, davg;
int n;

int main() {
	bool flag = true;
	double fuel = 0, price = 0;
	scanf( "%lf%lf%lf%d", &c, &dis, &davg, &n );
	for( int i = 0; i < n; ++i ) scanf( "%lf%lf", &s[i].second, &s[i].first );
	sort( s, s + n );
	if( s[0].first ) { puts( "The maximum travel distance = 0.00" ); return 0; }
	if( n == 0 ) { puts( "0.00" ); return 0; }
	for( int i = 0; i < n; ++i ) {
		double tdis = c * davg, tmin = s[i].second;
		int tpos = i, flag = false;
		if( i ) fuel -= ( s[i].first - s[i - 1].first ) / davg;
		for( int j = i + 1; j < n && s[j].first - ( s[i].first + tdis ) <= eps; ++j ) {
			flag = true;
			if( s[j].second <= tmin ) {
				tmin = s[j].second;
				tpos = j;
				break;
			}
		}
		if( !flag ) {
			if( ( dis - s[i].first ) - c * davg <= eps ) {
				double tfuel = max( 0.0, ( ( dis - s[i].first ) - fuel * davg ) / davg );
				price += tfuel * s[i].second;
				printf( "%.2f\n", price );
			} else printf( "The maximum travel distance = %.2f\n", s[i].first + c * davg );
			return 0;
		} else {
			if( tpos == i ) {
				if( ( dis - s[i].first ) - c * davg <= eps ) {
					double tfuel = max( 0.0, ( ( dis - s[i].first ) - fuel * davg ) / davg );
					price += tfuel * s[i].second;
					printf( "%.2f\n", price );
					return 0;
				}
				price += ( c - fuel ) * s[i].second;
				fuel = c;
			} else {
				double tfuel = max( 0.0, ( ( s[tpos].first - s[i].first ) - fuel * davg ) / davg );
				price += tfuel * s[i].second;
				fuel += tfuel;
			}
		}
	}
	return 0;
}
