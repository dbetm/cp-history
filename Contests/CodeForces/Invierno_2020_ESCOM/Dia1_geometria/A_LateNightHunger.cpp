// http://codeforces.com/group/4Drl6UlALp/contest/264643/problem/A
// tags: Geometría
#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
typedef vector<int> vi;
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0);
#define watch(x) cout << (#x) << " es " << x << endl;

struct point {
	// Coordenadas del punto (x,y)
	double x, y;
	// Consstructores
	point(): x(0), y(0) {}
	point(double x, double y): x(x), y(y) {}
	// Operaciones b ́asicas
	point operator+(const point & p)const{return point(x + p.x, y + p.y);}
	point operator-(const point & p)const{return point(x - p.x, y - p.y);}
	point operator*(const double & k)const{return point(x * k, y * k);}
	point operator/(const double & k)const{return point(x / k, y / k);}
	// Propiedades del punto
	double length()const{return sqrt(x*x + y*y);}
	point unit()const{return (*this) / length();}
	point perp() const{return point(-y, x);}
	point rotate(const double & ang) const{
		return point(x*cos(ang) - y*sin(ang), x*sin(ang) + y*cos(ang));
	}

	double cross(const point & p) const{return x * p.y - y * p.x;}
};


double area(vector<point> P);

int main() {
	int n;
	double x, y;
	double ai;
	double ans = 0;

	cin >> n;
	vector<point> poli(n);

	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		poli[n-1-i] = {x, y};
	}

	for (int i = 0; i < n; i++) {
		vector<point> aux;
		aux.push_back(poli[(i+1)%n]);
		aux.push_back(poli[(i+2)%n]);
		aux.push_back(poli[i]);
		ai = area(aux);
		//watch(ai)
		ans = max(ai, ans);
	}

	printf("%.10f\n", ans);

	return 0;
}

double area(vector<point> P){
	int n = P.size();
	double sum = 0;
	for(int i = 0; i < n; ++i) {
		sum += P[i].cross(P[(i+1)%n]);
	}
	return abs(sum / 2);
}
