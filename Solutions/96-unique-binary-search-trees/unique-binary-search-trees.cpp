#include <bits/stdc++.h>
using namespace std;

long long nCr(long long n, long long r) {
    long long res = 1;
    if (r > n - r) r = n - r;

    for (long long i = 0; i < r; i++) {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}

class Solution {
public:
    int numTrees(int n) {
        long long c = nCr(2 * n, n);
        return c / (n + 1);
    }
};