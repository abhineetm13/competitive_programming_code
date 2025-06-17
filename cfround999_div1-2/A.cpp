#include <bits/stdc++.h>

int main () {
    int t;
    std::cin >> t;

    for (int nTest = 0; nTest < t; nTest++) {
        int n;
        int n_odd = 0;
        int n_even = 0;
        std::cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            std::cin >> arr[i];
            if (arr[i] % 2 == 0) n_even++;
            else n_odd++;
        }
        if (n_even == 0) {
            std::cout << n_odd - 1 << std::endl;
        }
        else {
            std::cout << n_odd + 1 << std::endl;
        }
    }
}