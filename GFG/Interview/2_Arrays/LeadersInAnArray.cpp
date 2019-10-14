#include <bits/stdc++.h>
// https://practice.geeksforgeeks.org/problems/leaders-in-an-array/0
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
#define EPS 1.19209e-07
#define fastIO ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<double> vd;
lli MAX = 1e9+7;

void printLeaders(int arr[], int n);

int main() {
	fastIO
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        printLeaders(arr, n);
    }
	return 0;
}

void printLeaders(int arr[], int n) {
	vi aux;
	aux.push_back(arr[n-1]);
	for (int i = n-2; i >= 0; i--) {
		if(aux.back() <= arr[i]) {
			aux.push_back(arr[i]);
		}
	}

	for (size_t i = aux.size()-1; i > 0; i--) {
		cout << aux[i] << " ";
	}
	cout << aux[0] << endl;
}
