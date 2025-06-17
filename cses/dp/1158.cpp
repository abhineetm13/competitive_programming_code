#include <bits/stdc++.h>

int h[1000];  // book prices
int s[1000];  // book number of pages
int dp[1000][100001] = {{0}};

int main () {
    int n, x;
    std::cin >> n >> x;

    for (int i = 0; i < n; i++) {
        std::cin >> h[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> s[i];
    }

    dp[0][h[0]] = s[0];
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= x; j++) {
            dp[i][j] = dp[i-1][j];
            if (j - h[i] >= 0) {
                dp[i][j] = std::max(dp[i][j], dp[i-1][j - h[i]]+s[i]);
            }
        }
    }

    int max = -1;
    for (int i = 0; i <= x; i++) {
        if (dp[n-1][i] > max)
            max = dp[n-1][i];
    }

    std::cout << max << std::endl;

}