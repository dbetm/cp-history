#include <bits/stdc++.h>

using namespace std;

vector < int > getRecord(vector < int > s){
    vector < int > ss;
    int highest = 0, lowest = 0;
    int long max, min;
    max = s[0];
    min = s[0];
    for(unsigned int i = 1; i < s.size(); i++) {
		if(s[i] > max) {
			highest++;
			max = s[i];
		}
		else if(s[i] < min) {
			lowest++;
			min = s[i];
		}
	}
    ss.push_back(highest);
    ss.push_back(lowest);
    return ss;
}

int main() {
    int n;
    cin >> n;
    vector < int > s(n);
    for(int s_i = 0; s_i < n; s_i++){
       cin >> s[s_i];
    }
    vector < int > result = getRecord(s);
    cout << result[0] << " " << result[1] << endl;
    return 0;
}
