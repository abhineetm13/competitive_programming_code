#include <bits/stdc++.h>

int main () {
    int t; std::cin >> t;

    for (int nTest = 0; nTest < t; nTest++) {
        std::string s;
        std::cin >> s;
        long unsigned n = s.size();

        int first_0 = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                first_0 = i;
                break;
            }
        }

        int first_1 = -1;
        for (int i = first_0 + 1; i < n; i++) {
            if (s[i] == '1') {
                first_1 = i;
                break;
            }
        }

        if (first_0 == -1) {
            std::cout << n << " " << n << " ";
        }
        else{
            if (first_1 == -1) {
                std::cout << 1 << " " << n - first_0 << " ";
            }
            else if (first_1 - first_0 <= first_0) {
                std::cout << 2*first_0 - first_1 + 1 << " " << n - first_1 + first_0 << " ";
            }
            else {
                std::cout << 1 << " " << n - first_0 << " ";
            }
        }
        std::cout << 1 << " " << n << std::endl;
    }
}