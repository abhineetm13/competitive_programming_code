#include <bits/stdc++.h>

int MOD = 1e9 + 7;

int main () {
    int t;
    std::cin >> t;

    std::vector<int> inputs(t);
    int max = 0;

    for (int nTest = 0; nTest < t; nTest++) {
        int n;
        std::cin >> n;
        if (n > max) max = n;
        inputs[nTest] = n;
    }

    long long a[max];
    long long b[max];
    a[0] = 1;
    b[0] = 1;

    for (int i = 1; i < max; i++) {
        a[i] = (2*a[i - 1] + b[i - 1]) % MOD;
        b[i] = (a[i - 1] + 4*b[i - 1]) % MOD;
    }

    for (int nTest = 0; nTest < t; nTest++) {
        int n = inputs[nTest];
        std::cout << (a[n - 1] + b[n - 1]) % MOD << std::endl; 
    }

} 