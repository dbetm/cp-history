#include <iostream>
#include <vector>
using namespace std;

bool validator(int s, int t, int p, int d);

int main() {
    int distance, apples = 0, oranges = 0;
    int s;
    int t;
    cin >> s >> t;
    int a;
    int b;
    cin >> a >> b;
    int m;
    int n;
    cin >> m >> n;

    for(int i = 0; i < m; i++){
       cin >> distance;
       if(validator(s, t, a, distance)) apples++;
    }

    for(int i = 0; i < n; i++){
       cin >> distance;
       if(validator(s, t, b, distance)) oranges++;
    }

    cout << apples << endl << oranges << endl;

    return 0;
}

bool validator(int s, int t, int p, int d) {
  int val = p + d;
  if(val >= s and val <= t) return true;
  else return false;
}
