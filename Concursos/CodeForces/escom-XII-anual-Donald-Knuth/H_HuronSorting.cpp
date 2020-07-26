#include <bits/stdc++.h>
//
// Tag(s):
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
#define EPS 1.19209e-07
#define fastIO ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<double> vd;
lli MAX = 1e9+7;

string compute(int n, int k);
void swap(int firstIndex, int secondIndex, vector<int> &arr, int &swaps);
int indexOfMinimum(int startIndex, int n, vector<int> &arr);
void selectionSort(int n, vector<int> &arr, int &swaps, int k);

int main() {
    fastIO
    int t, n, k;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        cout << compute(n, k) << endl;
    }
	return 0;
}

string compute(int n, int k) {
    vector<int> arr(n);
    string ans = "No";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int swaps = 0;
    selectionSort(n, arr, swaps, k);

    if(swaps == k) ans = "Yes";

    return ans;
}

void swap(int firstIndex, int secondIndex, vector<int> &arr, int &swaps) {
    int temp = arr[firstIndex];
    arr[firstIndex] = arr[secondIndex];
    arr[secondIndex] = temp;
    swaps++;
}

int indexOfMinimum(int startIndex, int n, vector<int> &arr) {
    int minValue = arr[startIndex];
    int minIndex = startIndex;

    for (int i = minIndex + 1; i < n; i++) {
        if(arr[i] < minValue) {
            minIndex = i;
            minValue = arr[i];
        }
    }
    return minIndex;
}

void selectionSort(int n, vector<int> &arr, int &swaps, int k) {
    int ref;
    for (int i = 0; i < n; i++) {
        ref = indexOfMinimum(i, n, arr);
        swap(i, ref, arr, swaps);
        if(swaps > k) return;
    }
}
