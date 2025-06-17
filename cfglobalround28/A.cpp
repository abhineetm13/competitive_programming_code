#include <bits/stdc++.h>

int main () {
    int t; std::cin >> t;

    for (int i = 0; i < t; i++) {
        int x; std::cin >> x;
        if (x % 33 == 0) std::cout << "YES" << std::endl;
        else std::cout << "NO" << std::endl;
    }
}