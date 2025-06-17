#include <bits/stdc++.h>

int MOD = 1e9 + 7;

int main () {
    int n, x;
    std::cin >> n >> x;

    std::vector<int> c(n);
    for (int i = 0; i < n; i++)
        std::cin >> c[i];

    std::vector<unsigned long long> dp(x+1, 0);
    dp[0] = 1;

    for (int i = 1; i <= x; i++) {
        for (int j = 0; j < n; j++) {
            if (i-c[j] >= 0) {
                dp[i] += dp[i-c[j]];
            }
        }
        dp[i] %= MOD;
    }

    std::cout << dp[x] << std::endl;
}