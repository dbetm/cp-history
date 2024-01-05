#include <bits/stdc++.h>
//
// Tag(s):
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
#define EPS 1.19209e-07
#define fastIO ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<double> vd;
lli MAX = 1e9+7;

int getCost(int x, int y, string &s);
int getCostByReplace(int x, int y, string &s, char character, int index);

int main() {
    fastIO
    string s;
    int t, x, y;
    cin >> t;

    for (int r = 1; r <= t; ++r) {
        cin >> x >> y >> s;

        cout << "Case #" << r << ": " << getCost(x, y, s) << endl;
    }


	return 0;
}

int getCost(int x, int y, string &s) {
    int n = s.size();
    int cost = 0;

    for (int i = 0; i < n; ++i) {
        if(s[i] == '?') {
            if(i <= (n-1) and s[i+1] == '?') {
                if(i == 0 and x < y) s[0] = 'J';
                else if(i == 0 and y < x) s[0] = 'C';
                else {
                    s[i+1] = s[i-1];
                }
            }

            int costC = getCostByReplace(x, y, s, 'C', i);
            int costJ = getCostByReplace(x, y, s, 'J', i);

            if(costC < costJ) {
                //cost += costC;
                s[i] = 'C';
            }
            else {
                //cost += costJ;
                s[i] = 'J';
            }

        }
        /*
        if(s[i] == 'C' and s[i+1] == 'J') cost += x;
        else if(s[i] == 'J' and s[i+1] == 'C') cost += y;
        else {
            if(s[i+1] == '?') {
                if(i == 0 and s[0] == '?') {
                    if(x < y) s[0] = 'J';
                    else s[0] = 'C';
                }
                else s[i+1] = s[i-1];
            }
            int costC = getCostByReplace(x, y, s, 'C', i);
            int costJ = getCostByReplace(x, y, s, 'J', i);

            if(costC < costJ) {
                cost += costC;
                s[i] = 'C';
            }
            else {
                cost += costJ;
                s[i] = 'J';
            }
        }
        */
    }

    for (int i = 0; i < n-1; ++i) {
        if(s[i] == 'C' and s[i+1] == 'J') cost += x;
        else if(s[i] == 'J' and s[i+1] == 'C') cost += y;
    }

    //watch(s)
    return cost;
}

int getCostByReplace(int x, int y, string &s, char character, int index) {
    int n = s.size();
    int cost = 0;

    if(index == 0 and n > 1 and character == 'C' and s[index+1] == 'J') {
        cost = x;
    }
    else if(index == (n-1) and n > 1 and character == 'J' and s[index-1] == 'C') {
        cost = y;
    }
    else if(n > 2) {
        if(character == 'C' and s[index+1] == 'J') cost += x;
        else if(character == 'J' and s[index+1] == 'C') cost += y;

        if(s[index-1] == 'C' and character == 'J') cost += x;
        else if(s[index-1] == 'J' and character == 'C') cost += y;
    }

    return cost;
}
