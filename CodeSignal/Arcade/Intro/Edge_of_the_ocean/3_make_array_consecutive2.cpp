/*
Ratiorg got statues of different sizes as a present from CodeMaster for his
birthday, each statue having an non-negative integer size. Since he likes to make
things perfect, he wants to arrange them from smallest to largest so that each
statue will be bigger than the previous one exactly by 1. He may need some
additional statues to be able to accomplish that. Help him figure out the minimum number of additional statues needed.

Example:
For statues = [6, 2, 3, 8], the output should be
makeArrayConsecutive2(statues) = 3.

Ratiorg needs statues of sizes 4, 5 and 7.
*/

#include <bits/stdc++.h>

using namespace std;

int makeArrayConsecutive2(vector<int> statues) {
    int mayor = statues[0];
    int menor = statues[0];

    for(size_t i = 1; i < statues.size(); i++) {
        if(statues[i] > mayor) {
            mayor = statues[i];
        }
        if(statues[i] < menor) {
            menor = statues[i];
        }
    }

    return (mayor - menor) - statues.size() + 1;
}

int main(int argc, char const *argv[]) {
    vector <int> A;
    int n, num;
    // Number of element of the vector
    cin >> n;

    while(n--) {
        cin >> num;
        A.push_back(num);
    }
    cout << makeArrayConsecutive2(A) << endl;
    return 0;
}
