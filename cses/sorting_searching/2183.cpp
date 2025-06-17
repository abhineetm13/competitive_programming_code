#include <bits/stdc++.h>

int main () {
    int n; std::cin >> n;
    std::vector<int> v(n);
    for (int i = 0; i < n; i++) std::cin >> v[i];
    std::sort(v.begin(), v.end());

    long long x = 1;
    for (int i = 0; i < n; i++) {
        if (v[i] > x) {
            std::cout << x << std::endl;
            return 0;
        }
        else {
            x += v[i];
        }
    }
    std::cout << x << std::endl;

}