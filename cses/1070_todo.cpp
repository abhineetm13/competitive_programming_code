#include <bits/stdc++.h>

int main () {
    int n; std::cin >> n;
    if (n == 1) {
        std::cout << "1" << std::endl;
    }
    else if (n <= 3) {
        std::cout << "NO SOLUTION" << std::endl;
    }
    else if (n == 4) {
        std::cout << "3 1 4 2" << std::endl;
    }
    else {
        for (int i = 0; i < (n + 1) / 2; i++) {
            std::cout << 2 * i + 1 << " ";
        }
        for (int i = 0; i < n / 2; i++) {
            std::cout << 2 * i + 2 << " ";
        }
        std::cout << std::endl;
    }
}