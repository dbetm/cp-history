#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/Matriz-de-Ecuaciones#problems
using namespace std;

#define EPS 1.19209e-07
#define INF 1000000

// Método de eliminación
int gauss (vector < vector<double> > a, vector<double> & ans) {
    int n = (int) a.size();
    int m = (int) a[0].size() - 1;

    vector<int> where (m, -1);
    for (int col=0, row=0; col<m && row<n; ++col) {
        int sel = row;
        for (int i=row; i<n; ++i)
            if (abs (a[i][col]) > abs (a[sel][col]))
                sel = i;
        if (abs (a[sel][col]) < EPS)
            continue;
        for (int i=col; i<=m; ++i)
            swap (a[sel][i], a[row][i]);
        where[col] = row;

        for (int i=0; i<n; ++i)
            if (i != row) {
                double c = a[i][col] / a[row][col];
                for (int j=col; j<=m; ++j)
                    a[i][j] -= a[row][j] * c;
            }
        ++row;
    }

    ans.assign (m, 0);
    for (int i=0; i<m; ++i)
        if (where[i] != -1)
            ans[i] = a[where[i]][m] / a[where[i]][i];
    for (int i=0; i<n; ++i) {
        double sum = 0;
        for (int j=0; j<m; ++j)
            sum += ans[j] * a[i][j];
        if (abs (sum - a[i][m]) > EPS)
            return 0;
    }

    for (int i=0; i<m; ++i)
        if (where[i] == -1)
            return INF;
    return 1;
}


int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    vector <double> respuestas(n);
    vector < vector<double> > a(n);

    for (int i = 0; i < n; i++) {
        vector <double> aux(n+1);
        for (int j = 0; j <= n; j++) {
            cin >> aux[j];
        }
        a[i] = aux;
    }

    int ans = gauss(a, respuestas);

    for (unsigned int i = 0; i < respuestas.size(); i++) {
        cout << (int)round(respuestas[i]) << " ";
    }
    cout << endl;
    return 0;
}
