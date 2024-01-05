#include <bits/stdc++.h>
// Incorrecta
// Tag(s):
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
#define EPS 1.19209e-07
#define fastIO ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
typedef long long int lli;
typedef vector<int> vi;
map<int, pair<double, double>> personas;
lli n, m;


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
    // Más funciones
	double cross(const point & p) const{return x * p.y - y * p.x;}
    bool operator==(const point & p)const{return x == p.x && y == p.y;}
    bool operator!=(const point & p) const{return !(*this == p);}
    bool operator<(const point & p) const{
        if(x == p.x) return y < p.y;
        return x < p.x;
    }
    bool operator>(const point & p) const{
        if(x == p.x) return y > p.y;
        return x > p.x;
    }
};

vector<point> convexHull(vector<point> P);
point center_mass(vector<point> P);
double get_d(vector<point> P, point cm);

int main() {
    fastIO
    lli l, q, k, id;
    cin >> n >> m >> l;

    for (int i = 1; i <= l; i++) {
        pair<double, double> coordenada;
        cin >> coordenada.first >> coordenada.second;
        personas[i] = coordenada;
    }

    cin >> q;

    for (int i = 0; i < q; i++) {
        cin >> k;
        if(k == 1) {
            cout << 0.000000000 << endl;
        }
        else {
            vector<point> P(k);
            for (int j = 0; j < k; j++) {
                cin >> id;
                P[j].x = personas[id].first;
                P[j].y = personas[id].second;

            }
            vector<point> ch = convexHull(P);
            point cs = center_mass(ch);
            printf("%0.9f\n", get_d(ch, cs));
        }
    }

	return 0;
}

vector<point> convexHull(vector<point> P) {
    vector<point> L, U;
    sort(P.begin(), P.end());
    P.erase(unique(P.begin(), P.end()), P.end());
    int n = P.size();
    if(n <= 2) return P;
    for(int i = 0; i < n; ++i){
        while(L.size() >= 2 && (L[L.size()-1] - L[L.size()-2]).cross(P[i] - L[L.size()-1]) <= 0){
            L.pop_back();
        }
        L.push_back(P[i]);
    }
    for(int i = n-1; i >= 0; --i){
        while(U.size() >= 2 && (U[U.size()-1] - U[U.size()-2]).cross(P[i] - U[U.size()-1]) <= 0){
            U.pop_back();
        }
        U.push_back(P[i]);
    }
    L.pop_back(), U.pop_back();
    L.insert(L.end(), U.begin(), U.end());
    return L;
}

point center_mass(vector<point> points) {
    double xsum = 0.0;
    double ysum = 0.0;
    double area = 0.0;
    for(int i = 0; i < points.size() - 1; i++) {
        // I'm not a c++ guy... do you need to use pointers? You make the call here
        point p0 = points[i];
        point p1 = points[i+1];

        double areaSum = (p0.x * p1.y) - (p1.x * p0.y);

        xsum += (p0.x + p1.x) * areaSum;
        ysum += (p0.y + p1.y) * areaSum;
        area += areaSum;
    }
    return point(xsum / (area * 6), ysum / (area * 6));
}

double get_d(vector<point> P, point cm) {
    double ans = DBL_MAX;

    for(point p : P) {
        ans = min(ans, sqrt(pow(p.x - cm.x, 2) + pow(p.y - cm.y, 2)));
    }

    return ans;
}
