#include <bits/stdc++.h>

int main () {
    int t; std::cin >> t;

    for (int nTest = 0; nTest < t; nTest++) {
        int n; std::cin >> n;
        int k; std::cin >> k;

        std::vector<int> arr(n, 0);
        
        int ind = k - 1;
        int val = 1;
        for (int i = 0; i < n / k; i++) {
            arr[ind] = val;
            val++;
            ind += k;
        }

        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) {
                arr[i] = val;
                val++;
            }
        }

        for (int i = 0; i < n; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
}