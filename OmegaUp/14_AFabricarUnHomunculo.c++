#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    // Faster I/O
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<string> output;

    int n, m, i, num, target;
    cin >> n;
    set<int> materials;

    for (i = n-1; i >= 0; --i) {
        cin >> num;
        materials.insert(num);
    }

    cin >> m;
    for (i = m-1; i >= 0; --i) {
        cin >> target;
        if(materials.find(target) != materials.end())
            output.push_back("SI");
        else output.push_back("NO");
    }

    for(string ans : output)
        cout << ans << endl;

    return 0;
}
