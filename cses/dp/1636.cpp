// Was very sensitive to time:
//  Made dp array instead of vector
//  Made MOD as const
//  Split +=; % into two lines
//  I was initially sorting the array, it is not needed

#include <bits/stdc++.h>

const int MOD = 1e9 + 7;

long long dp[1000001]; 

int main () {
    int n, x;
    std::cin >> n >> x;
    std::vector<int> c(n);
    for (int i = 0; i < n; i++)
        std::cin >> c[i];

    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = c[i]; j <= x; j++) {
            dp[j] += dp[j - c[i]];
            dp[j] %= MOD;
        }
    }

    std::cout << dp[x] << std::endl;
}