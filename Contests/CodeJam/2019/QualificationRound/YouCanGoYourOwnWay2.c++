#include <bits/stdc++.h>
// Passes 3 cases sets
using namespace std;

string getOwnWay(int, string);

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    short t;
    cin >> t;
    string path;
    int n;
    for (short i = 1; i <= t; i++) {
        cin >> n;
        cin >> path;
        cout << "Case #" << i << ": " << getOwnWay(n, path) << endl;
    }
    return 0;
}

string getOwnWay(int n, string path) {
    string ans = (path[0] == 'S')? "E" : "S";
    bool flag = (ans == "E");
    // flag = true -> S // flag = false -> E
    for (unsigned int i = 1; i < path.size(); i++) {
        if(flag && path[i] != 'S') {
            ans += 'S';
            flag = false;
        }
        else if(flag && path[i] == 'S') {
            ans += 'E';
        }
        else if(!flag && path[i] != 'E') {
            ans += 'E';
            flag = true;
        }
        else if(!flag && path[i] == 'E') {
            ans += 'S';
        }
    }

    return ans;
}
