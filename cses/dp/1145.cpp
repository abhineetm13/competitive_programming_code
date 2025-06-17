#include <bits/stdc++.h>

int main () {
    int n; std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) std::cin >> arr[i];

    // dp[i] stores the min element found for a subsequence of length i+1
    std::vector<int> dp(n, INT_MAX);

    dp[0] = arr[0];

    for (int i = 1; i < n; i++) {
        auto it = std::lower_bound(dp.begin(), dp.end(), arr[i]);
        *it = arr[i];
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (dp[i] < INT_MAX) ans++;
    }

    std::cout << ans << std::endl;
}