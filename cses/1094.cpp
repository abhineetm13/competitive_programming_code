#include <bits/stdc++.h>

int main () {
    int n; std::cin >> n;

    long long num = 0;
    long long val;
    std::cin >> val;

    for (int i = 0; i < n - 1; i++) {
        long long val1;
        std::cin >> val1;
        if (val1 >= val) val = val1;
        else {
            num += (val - val1);
        }
    }

    std::cout << num << std::endl;
}