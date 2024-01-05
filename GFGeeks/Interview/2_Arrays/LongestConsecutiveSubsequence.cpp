#include <bits/stdc++.h>
// https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence/1/
using namespace std;
int findLongestConseqSubseq(int [], int );
int main() {
	int t;
	cin>>t;

	while(t--)
	{
		int n;
		cin>>n;

		int a[n];

		// input array elements
		for(int i=0;i<n;i++)
		    cin>>a[i];

		cout<< findLongestConseqSubseq(a, n)<<endl;

	}
	return 0;
}
/*This is a function problem.You only need to complete the function given below*/

// function to find longest consecutive subsequence
// n : size of array
// arr[] : input array
int findLongestConseqSubseq(int arr[], int n) {
    int ans = 0, aux;
    int num;

    sort(arr, arr+n);
    // Caso inicial
    num = arr[0];
    ans = 1;
    aux = ans;
    //cout << num << " ";
    for (int i = 1; i < n; i++) {
        // cout << arr[i] << " ";
        if((arr[i] - 1) == num) {
            num++;
            aux++;
        }
        else if(arr[i] == num) continue;
        else {
            ans = max(ans, aux);
            num = arr[i];
            aux = 1;
        }
    }
    ans = max(ans, aux);
    //cout << "\n-------" << endl;

    return ans;
}
