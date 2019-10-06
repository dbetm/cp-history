#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
// TLE
using namespace std;

int main() {
    int n, m, num;
    scanf("%d", &n);
    map<int, bool> dic;
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        dic.insert(make_pair(num, true));
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        scanf("%d", &num);
        try {
            if(dic[num]) printf("SI\n");
            else printf("NO\n");
        }
        catch(...) {
            printf("NO\n");
        }
    }

    return 0;
}
