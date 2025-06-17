#include <bits/stdc++.h>

long long MOD = 1e9 + 7;

int main () {
    int n; std::cin >> n;

    int n1 = std::max(n, 6);
    long long arr[n1];
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 4;
    arr[3] = 8;
    arr[4] = 16;
    arr[5] = 32;
    for (int i = 6; i < n; i++) {
        arr[i] = (arr[i - 1] + arr[i - 2] + arr[i - 3] + arr[i - 4] + arr[i - 5] + arr[i - 6]) % MOD;
    }

    std::cout << arr[n - 1] << std::endl;
}