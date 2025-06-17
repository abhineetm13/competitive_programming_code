#include <bits/stdc++.h>

int main () {
    int t;
    std::cin >> t;

    for (int nTest = 0; nTest < t; nTest++) {
        int n;
        std::cin >> n;
        std::vector<int> arr(n);
        for (int i = 0; i < n; i++) std::cin >> arr[i];

        bool yes = false;

        for (int i = 0; i < n - 1; i++) {
            int max = std::max(arr[i], arr[i + 1]);
            int min = std::min(arr[i], arr[i + 1]);
            if (max < 2*min) {
                std::cout << "YES" << std::endl;
                yes = true;
                break;
            }
        }
        if (!yes) {
            std::cout << "NO" << std::endl;
        }
    }

}