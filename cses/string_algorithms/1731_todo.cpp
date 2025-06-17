#include <bits/stdc++.h>


void kmp (std::string s, std::string s1, std::vector<int> &positions) {
    std::vector<int> jumps(s1.size(), 0);
    
}

int main () {
    std::string s;
    std::cin >> s;

    long unsigned n = s.size();
    std::vector<std::vector<long long>> arr (n, std::vector<long long>(n, 0));

    int k; std::cin >> k;
    for (int i = 0; i < k; i++) {
        std::string s1;
        std::cin >> s1;
        long unsigned l = s1.size();
        std::vector<int> positions;
        kmp(s, s1, positions);
        for (int i : positions) {
            arr[i][i + l - 1]++;
        }
    }

    std::vector<long long> ans(n, 0);
    ans[n - 1] = arr[n - 1][n - 1];
    for (int i = n - 2; i >= 0; i--) {
        ans[i] = arr[i][n - 1];
        for (long unsigned j = i + 1; j < n - 1; j++) {
            ans[i] += arr[i][j] * ans[j + 1];
        }
    }

    std::cout << ans[0] << std::endl;
}