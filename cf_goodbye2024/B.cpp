#include <bits/stdc++.h>

int main () {
    int t;
    std::cin >> t;

    for (int nTest = 0; nTest < t; nTest++) {
        int n;
        std::cin >> n;
        std::vector<int> l(n, 0), r(n, 0);
        std::vector<int> occ(2*n, 0);
        for (int i = 0; i < n; i++) {
            std::cin >> l[i] >> r[i];
            if (l[i] == r[i]) occ[l[i] - 1]++;
        }

        std::vector<int> num_zeroes(2*n, 0);
        if (occ[0] == 0) num_zeroes[0]++;
        for (int i = 1; i < 2*n; i++) {
            num_zeroes[i] = num_zeroes[i - 1];
            if (occ[i] == 0) num_zeroes[i]++;
        }

        for (int i = 0; i < n; i++) {
            if (l[i] == r[i]) {
                if (occ[l[i] - 1] == 1) std::cout << "1";
                else std::cout << "0";
            }
            else {
                if (l[i] == 1 && num_zeroes[r[i] - 1] == 0) std::cout << "0";
                else if (num_zeroes[r[i] - 1] == num_zeroes[l[i] - 2]) std::cout << "0";
                else std::cout << "1";
            }
        }

        std::cout << std::endl;
    }
}