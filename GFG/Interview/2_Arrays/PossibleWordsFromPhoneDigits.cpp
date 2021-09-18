#include <bits/stdc++.h>
// https://practice.geeksforgeeks.org/problems/possible-words-from-phone-digits-1587115620/1/
// Tag(s): Arrays
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
#define EPS 1.19209e-07
#define fastIO ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<double> vd;
lli MAX = 1e9+7;

class Solution {
private:
    map<int, string> keyboard;
public:
    Solution() {
        int asciiCont = 97;
        for (int i = 2; i <= 9; ++i) {
            this->keyboard[i] = "";
            int upper = (i == 7 or i == 9) ? 4 : 3;
            for (int j = 0; j < upper; j++, asciiCont++) {
                this->keyboard[i] += char(asciiCont);
            }
        }
    }
    vector<string> possibleWords(int a[], int N) {
        //sort(a, a+N);
        vector<string> ans;
        int indices[N] = {0};

        int totalWords = 1;

        for (int i = 0; i < N; i++) {
            totalWords *= this->keyboard[a[i]].size();
        }

        for (int i = 0; i < totalWords; i++) {
            string str = "";
            for(int j = 0; j < N; j++) {
                //watch(this->keyboard[a[j]])
                str += this->keyboard[a[j]].at(indices[j]);
            }
            //watch(str)
            ans.push_back(str);

            int x = N-1;
            do {
                indices[x]++;

                int upper = (a[x] == 7 or a[x] == 9) ? 4 : 3;

                if(indices[x] == upper) {
                    indices[x] = 0;
                    x--;
                }
                else break;
            } while(x >= 0);
        }

        return ans;
    }
};

int main() {
    fastIO

    int T;
    cin >> T;

    Solution sol;

    while(T--) {
        int n;
        cin >> n;

        int a[n];

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<string> res = sol.possibleWords(a, n);

        for(string str : res) cout << str << " ";
        cout << endl;
    }

	return 0;
}
