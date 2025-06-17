#include <bits/stdc++.h>

int main () {
    int t;
    std::cin >> t;

    while (t--) {
        int n, m;
        std::cin >> n >> m;
        std::cout << std::max(n ,m) + 1 << '\n';
    }
}