#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/Ferret-Chains#problems
using namespace std;

vector<int> nums;

int len;

int getLenFerretChain(int num);
int obtenerM(int num);
int obtenerA(int m);
int obtenerD(int m);

int main() {
    int number;
    do {
        cin >> number;
        if(number == 0) break;
        nums.clear();
        cout << "Chain length " << getLenFerretChain(number) << endl;
    } while(true);

    return 0;
}

// M = A - D
int getLenFerretChain(int num) {
    int len = 0;
    do {
        if(find(nums.begin(), nums.end(), num) != nums.end()) break;
        nums.push_back(num);
        num = obtenerM(num);
        len++;
    } while(true);
    return len;
}

int obtenerM(int num) {
    int m;
    string numStr = to_string(num);
    string a = numStr;
    sort(a.begin(), a.end());
    string d = a;
    reverse(d.begin(), d.end());
    m = stoi(d) - stoi(a);
    return m;
}
