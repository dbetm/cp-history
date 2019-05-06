#include <bits/stdc++.h>

using namespace std;

vector <string> catAndMouse(int x, int y, int z) {
    vector < string > answer;
    if(abs(z - x) > abs(z - y)) answer.push_back("Cat B");
    else if(abs(z - x) < abs(z - y)) answer.push_back("Cat A");
    else answer.push_back("Mouse C");

    return answer;
}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        int x;
        int y;
        int z;
        cin >> x >> y >> z;
        vector <string> result = catAndMouse(x, y, z);
        for (ssize_t i = 0; i < result.size(); i++) {
            cout << result[i] << (i != result.size() - 1 ? " " : "");
        }
        cout << endl;


    }
    return 0;
}
