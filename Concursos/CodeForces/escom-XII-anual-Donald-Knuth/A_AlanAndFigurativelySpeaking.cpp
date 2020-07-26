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

int main() {
    fastIO
    string str;
    cin >> str;
    int len = str.size();
    string ans = "";
    for (int i = 0; i < len; i++) {
        if(str[i] == 'O' || str[i] == 'o') ans += "0";
        else if(str[i] == 'I' || str[i] == 'i') ans += "1";
        else if(str[i] == 'Z' || str[i] == 'z') ans += "2";
        else if(str[i] == 'E' || str[i] == 'e') ans += "3";
        else if(str[i] == 'A' || str[i] == 'a') ans += "4";
        else if(str[i] == 'S' || str[i] == 's') ans += "5";
        else if(str[i] == 'G' || str[i] == 'g') ans += "6";
        else if(str[i] == 'T' || str[i] == 't') ans += "7";
        else if(str[i] == 'B' || str[i] == 'b') ans += "8";
        else ans += str[i];
    }

    cout << ans << endl;

	return 0;
}
