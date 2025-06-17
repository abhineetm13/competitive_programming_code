#include <bits/stdc++.h>

const int MOD = 1e9 + 7;

char grid[1001][1001];
long long dp[1001][1001];

int main () {
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            std::cin >> grid[i][j];
        }
    }

    if (grid[n][n] == '*') {
        std::cout << 0 << std::endl;
        return 0;
    }
    dp[n][n] = 1;
    for (int i = n-1; i > 0; i--) {
        if (grid[n][i] == '*')
            dp[n][i] = 0;
        else
            dp[n][i] = dp[n][i+1];
        if (grid[i][n] == '*')
            dp[i][n] = 0;
        else
            dp[i][n] = dp[i+1][n];
    }

    for (int i = n-1; i > 0; i--) {
        for (int j = n-1; j > 0; j--) {
            if (grid[i][j] == '*')
                dp[i][j] = 0;
            else
                dp[i][j] = (dp[i+1][j] + dp[i][j+1]) % MOD;
        }
    }

    std::cout << dp[1][1] << std::endl;
}