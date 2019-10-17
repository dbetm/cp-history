#include <bits/stdc++.h>
// https://www.hackerrank.com/challenges/3d-surface-area/problem
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
#define EPS 1.19209e-07
#define fastIO ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<double> vd;
lli MAX = 1e9+7;
int arr[100][100];

lli get3DSurfaceArea(int height, int weigth);

int main() {
	fastIO
    int height, weigth;

    cin >> height >> weigth;
    for (int i = 0; i < height; i++)
        for (int j = 0; j < weigth; j++) cin >> arr[i][j];

    cout << get3DSurfaceArea(height, weigth) << endl;

	return 0;
}

lli get3DSurfaceArea(int height, int weigth) {
    lli ans = (height * weigth) * 2;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < weigth; j++) {
            // izquierda
            if(j-1 < 0) ans += arr[i][j];
            else if(arr[i][j-1] < arr[i][j]) ans += arr[i][j] - arr[i][j-1];
            // adelante
            if(i-1 < 0) ans += arr[i][j];
            else if(arr[i-1][j] < arr[i][j]) ans += arr[i][j] - arr[i-1][j];
            // derecha
            if(j+1 >= weigth) ans += arr[i][j];
            else if(arr[i][j+1] < arr[i][j]) ans += arr[i][j] - arr[i][j+1];
            // atrás
            if(i+1 >= height) ans += arr[i][j];
            else if(arr[i+1][j] < arr[i][j]) ans += arr[i][j] - arr[i+1][j];
        }
    }

    return ans;
}
