#include <bits/stdc++.h>

using namespace std;

int partition(int arr[], int start, int end) {
    int i = start;
    int pivote = arr[end];

    for (int j = start; j < end; j++) {
        if(arr[j] < pivote) {
            swap(arr[i++], arr[j]);
        }
    }

    swap(arr[i], arr[end]);
    return i;
}

void quicksort(int arr[], int start, int end) {
    if(start >= end) {
        return;
    }

    int pivote = partition(arr, start, end);
    quicksort(arr, start, pivote-1);
    quicksort(arr, pivote+1, end);
}

int main() {
    int n;
    cout << "Type n: " << endl;
    cin >> n;
    int arr[n];
    cout << "Type each element separated with spaces: " << endl;
    for (int i = 0; i < n; i++) cin >> arr[i];

    quicksort(arr, 0, n-1);

    for (int i = 0; i < n-1; i++) cout << arr[i] << " ";
    cout << arr[n-1] << endl;

    return 0;
}
