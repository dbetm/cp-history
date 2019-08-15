#include <bits/stdc++.h>
// https://www.hackerrank.com/challenges/encryption/problem?h_r=profile
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
#define EPS 1.19209e-07
#define fastIO() ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<double> vd;
lli MAX = 1e9+7;

int main() {
    fastIO();
    string input;
    getline(cin, input);
    string::iterator end_pos = std::remove(input.begin(), input.end(), ' ');
    input.erase(end_pos, input.end());
    int len = input.size();
    int l_min = ceil(sqrt(len));
    vector <string> grid;
    string col;
    int i = 0;
    while(i < len) {
        col = "";
        for (int k = 0; k < l_min && i < len; k++, i++) {
            col += input[i];
        }
        grid.push_back(col);
    }

    int filas = grid.size();
    for (int j = 0; j < l_min; j++) {
        for (int k = 0; k < filas; k++) {
            if(j < (int)grid[k].size()) cout << grid[k][j];
            else break;
        }
        cout << " ";
    }
    cout << endl;

	return 0;
}
