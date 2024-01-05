#include <bits/stdc++.h>

using namespace std;

void display(int arr[], int n);

int main() {
    int n = 12;
    int coins[] = {1, 5, 10};
    int ways[n+1] = {};
    ways[0] = 1;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n+1; j++) {
            if(coins[i] <= j) {
                ways[j] = ways[j-coins[i]] + ways[j];
            }
        }
        cout << "Comparando moneda de $" << coins[i] << endl;
        display(ways, n+1);
        cin.get();
    }

    return 0;
}

void display(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
