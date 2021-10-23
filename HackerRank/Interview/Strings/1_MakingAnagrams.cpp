#include <bits/stdc++.h>
// https://www.hackerrank.com/challenges/ctci-making-anagrams/problem
// Tag(s): cadenas, hashmap
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
#define EPS 1.19209e-07
#define fastIO ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);

const int ALPHA_SIZE = 26;

int makeAnagram(string a, string b) {
    int ans = 0;

    int mapA[ALPHA_SIZE] = {0};
    int mapB[ALPHA_SIZE] = {0};

    for(const char c : a) mapA[int(c)-97]++;
    for(const char c : b) mapB[int(c)-97]++;

    for (int i = 0; i < 26; ++i) {
        ans += abs(mapA[i] - mapB[i]);
    }

    return ans;
}

int main() {
    fastIO
    string a, b;
    cin >> a;
    cin >> b;

    cout << makeAnagram(a, b) << endl;

	return 0;
}
