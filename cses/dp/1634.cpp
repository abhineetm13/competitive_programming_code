#include <bits/stdc++.h>

int main () {
    int n, x;
    std::cin >> n >> x;

    std::vector<int> c(n);
    for (int i = 0; i < n; i++) {
        std::cin >> c[i];
    }

    std::vector<int> dp(x+1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= x; i++) {
        int min = INT_MAX;
        for (int j = 0; j < n; j++) {
            if ((i - c[j] >= 0) && dp[i-c[j]] < INT_MAX && dp[i-c[j]]+1 < min) {
                min = dp[i-c[j]]+1;
            }
        }
        dp[i] = min;
    }
    if (dp[x] < INT_MAX) 
        std::cout << dp[x] << std::endl;
    else 
        std::cout << -1 << std::endl;
}