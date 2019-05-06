#include <bits/stdc++.h>
// https://www.hackerrank.com/challenges/jumping-on-the-clouds/problem
using namespace std;

int main(int argc, char const *argv[]) {
    int n, cont = 0, j = 0;
    // Read number of clouds
    cin >> n;
    // Initialize an array of size n
    int a[n];
    // Read the value of each cloud
    for (size_t i = 0; i < n; i++) {
        cin >> a[i];
    }
    // Iterate array for count the min steps, avoid the thundercloud [1]
    // Steps 1 or 2 size
    while(j < n - 1) {
        cont++;
        if(a[j + 2] != 1) j += 2;
        else j++;
    }
    // Print the min # clouds
    cout << cont << endl;
    return 0;
}
