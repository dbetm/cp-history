#include <bits/stdc++.h>

using namespace std;

bool almostIncreasingSequence(std::vector<int> sequence) {
    unsigned int len = sequence.size();
    int cont1 = 0, cont2 = 0, j = sequence.size() - 2;
    bool ans1 = true, ans2 = true;

    for (size_t i = 1; i < len; i++, j--) {
        if(ans1 && i + 1 < len) {
            if(sequence) {

            }
            if(!(sequence[i - 1] < sequence[i] < sequence[i + 1])) {
                cont1++;
                if(cont1 > 2) ans1 = false;
            }
        }
        if(ans2 && j - 1 >= 0) {
            if(!(sequence[j + 1] > sequence[j] > sequence[j - 1])) {
                cont2++;
                if(cont2 > 2) ans1 = false;
            }
        }
    }
    return ans1 || ans2;
}

int main() {
    vector <int> A;
    int n, num;
    // Number of element of the vector
    cin >> n;

    while(n--) {
        cin >> num;
        A.push_back(num);
    }
    cout << almostIncreasingSequence(A) << endl;
    return 0;
}
