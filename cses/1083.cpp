#include <bits/stdc++.h>

int main () {
    int n;
    std::cin >> n;

    std::vector<int> v(n, 0);
    for (int i = 0; i < n - 1; i++) {
        int x;
        std::cin >> x;
        v[x - 1] = 1;
    }
    for (int i = 0; i < n; i++) {
        if (v[i] == 0) {
            std::cout << i + 1 << std::endl;
            break;
        }
    }
}