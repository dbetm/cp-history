#include <bits/stdc++.h>
// Parcialmente correcta
using namespace std;

int main(int argc, char const *argv[]) {
    int n, num;
    long long int total = 0;
    map<int, int> conejos;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> num;
        try {
            if(conejos.at(num) >= 1) conejos[num]++;
        }
        catch(...) {
            conejos.insert(pair<int, int>(num, 1));
        }
    }

    map<int, int>::iterator itr;
    for(itr = conejos.begin(); itr != conejos.end(); ++itr) {
        n = itr->second;
        int num = itr->first;
        if(n == 1) {
            total += num+1;
        }
        else if(num & 1) { // impar
            total += (n / num) * (num);
        }
        else { // par
            if(num == 0) total += n;
            else total += (n / num) * (num + 1);
        }
    }

    cout << total << endl;

    return 0;
}
