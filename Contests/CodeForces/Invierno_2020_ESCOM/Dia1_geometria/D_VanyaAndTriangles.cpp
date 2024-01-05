#include <bits/stdc++.h>
//
// tags: geometría
using namespace std;
typedef long long int lli;
typedef vector<int> vi;
#define EPS 1.19209e-07
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0);
#define watch(x) cout << (#x) << " es " << x << endl;

struct point {
	// Coordenadas del punto (x,y)
	double x, y;
	// Constructores
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

	cin >> n;
	vector<point> poli(n);
	//vector<pair<int, int>> aux(n);

	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		poli[i] = {x, y};
	}

	if(n == 1 || n == 2) cout << 0 << endl;
	else {
		int ans = 0;
		double ai;
        int p = 31;
        set<int> triangulos;
		//sort(aux.begin(), aux.end());

		// for (int i = 0; i < n; i++) {
		// 	poli[i]={aux[i].first, aux[i].second};
		// }

		for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int x1 = poli[i].x, x2 = poli[(i+j+1)%n].x, x3 = poli[(i+j+2)%n].x;
                int y1 = poli[i].y, y2 = poli[(i+j+1)%n].y, y3 = poli[(i+j+2)%n].y;

                int id = x1*y1*p + x2*y2*p + x3*y3*p;
                auto pos = triangulos.find(id);
                if(pos == triangulos.end()) {
                    vector<point> aux;
                    aux.push_back(poli[i]);
                    aux.push_back(poli[(i+j+1)%n]);
                    aux.push_back(poli[(i+j+2)%n]);
                    ai = area(aux);
                    if(ai >EPS) ans++;
                    triangulos.insert(id);
                }
            }
		}
		cout << ans << endl;
	}
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
