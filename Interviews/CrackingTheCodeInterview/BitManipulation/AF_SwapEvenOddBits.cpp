#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;


map<int, int> simpleCases = {
    {0, 0}, {1, 2}, {2, 1}, {3, 3}
};


int swapBitsPair(int x) {
    return simpleCases.at(x);
}


int swapEvenOddsBits(int n) {
    long int factor = 1;
    long int res = 0;

    while(n) {
        int residual = n % 4;
        res += factor * swapBitsPair(residual);

        // n /= 4;
        n >>= 2;
        factor *= 4;
    }

    return res;
}

int swapEvenOddsBitsOpt(int n) {
    int oddBitsMask = 0xaaaaaaaa;
    int evenBitsMask = 0x55555555;

    return ( ((n & oddBitsMask) >> 1) | ((n & evenBitsMask) << 1) );
}


int invoke(int n, string func_name, int (*func)(int)) {
    auto start = high_resolution_clock::now();
    // cout << func(n) << endl;
    func(n);
    auto end_ = high_resolution_clock::now();
    // Calculate the elapsed time in microseconds
    auto duration = duration_cast<microseconds>(end_ - start);
    // cout << func_name << ": " << duration.count() << " microseconds" << endl;
    return duration.count();
}


int main() {
    int n;
    // cin >> n;
    int noOptTotal = 0;
    int optTotal = 0;

    for(int i = 100; i <= 100000; ++i) {
        noOptTotal += invoke(i, "swapEvenOddsBits", &swapEvenOddsBits);
        optTotal += invoke(i, "swapEvenOddsBitsOpt", &swapEvenOddsBitsOpt);
    }

    cout << "Non-optimized function total time: " << noOptTotal << " microseconds" << endl;
    cout << "Optimized function total time: " << optTotal << " microseconds" << endl;

    return 0;
}
