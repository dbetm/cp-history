#include <bits/stdc++.h>

using namespace std;

int lowestTriangle(double base, double area){
    double ans = (2 * area) / base;
    return ceil(ans);
}

int main() {
    int base;
    int area;
    cin >> base >> area;
    int height = lowestTriangle(base, area);
    cout << height << endl;
    return 0;
}
