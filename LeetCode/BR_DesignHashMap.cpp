#include <bits/stdc++.h>
// https://leetcode.com/problems/design-hashmap/
// Tag(s): data structures, hashing
using namespace std;
#define watch(x) cout << (#x) << " is " << x << endl;

const int MAX = 1e6+1;

class MyHashMap {
private:
    int array[MAX];
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        memset(array, -1, sizeof(array));
    }

    /** value will always be non-negative. */
    void put(int key, int value) {
        this->array[key] = value;
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        return this->array[key];
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        this->array[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

int main() {
    MyHashMap hashMap;
    hashMap.put(1, 1);
    hashMap.put(2, 2);
    cout << hashMap.get(1) << endl;
    cout << hashMap.get(3) << endl;
    hashMap.put(2, 1);
    cout << hashMap.get(2) << endl;
    hashMap.remove(2);
    cout << hashMap.get(2) << endl;

    return 0;
}
