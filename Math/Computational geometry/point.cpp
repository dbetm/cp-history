#include <bits/stdc++.h>

using namespace std;

struct point {
    // componentes del punto
    double x, y;
    // Constructores
    point(): x(0), y(0) {}
    point(double x, double y) : x(x), y(y) {}
    // Operaciones básicas
    point operator+(const point &p)const{return point(x + p.x, y + p.y);}
    point operator-(const point &p)const{return point(x - p.x, y - p.y);}
    point operator*(const double &k)const{return point(x * k, y * k);}
    point operator/(const double &k)const{return point(x / k, y / k);}
    bool operator==(const point &p)const{return x == p.x && y == p.y;}
    bool operator!=(const point &p)const{return !(*this == p);}
    // comparación con orden lexicográfico
    bool operator<(const point &p) const {
        if(x == p.x) return y < p.y;
        return x < p.x;
    }
    bool operator>(const point &p) const {
        if(x == p.x) return y > p.y;
        return x > p.x;
    }
    // Propiedades del punto
    double length()const{return sqrt(x*x + y*y);}
    point unit()const{return (*this) / length();}
    point perp()const{return point(-y, x);}
    point rotate(const double &ang) const {
        return point(x*cos(ang) - y*sin(ang), x*sin(ang) + y*cos(ang));
    }
};

// Utils
istream& operator>>(istream& is, point &p) {
    return is >> p.x >> p.y;
}
ostream& operator<<(ostream &os, const point &p) {
    return os << "(" << p.x << ", " << p.y << ")";
}

/*Ejemplo:
+ Se leen 2 puntos P y Q y un ángulo theta.
+ Se imprime como salida el punto que resulta de rotar el punto Q
alrededor de P con un ángulo theta en sentido antihorario.
*/
int main() {
    point p, q;
    double theta;
    cout << "Type P: ";
    cin >> p;
    cout << "Type Q: ";
    cin >> q;
    cout << "Type theta: ";
    cin >> theta;
    point q_rotated = p + (q - p).rotate(theta);
    cout << "Q': " << q_rotated << endl;
    return 0;
}
