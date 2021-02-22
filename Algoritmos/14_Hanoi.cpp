#include <iostream>

using namespace std;

int countSteps(int n) {
    if(n == 0) return 0;

    return countSteps(n-1) + 1 + countSteps(n-1);
}

int main() {
    int number_disks;
    cin >> number_disks;
    // 2^(n) - 1
    cout << countSteps(number_disks) << endl;
    return 0;
}
