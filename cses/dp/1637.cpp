#include <bits/stdc++.h>

int max_digit (int n) {
    std::vector<int> v;
    while (n > 0) {
        v.push_back(n % 10);
        n /= 10;
    }

    int max = 0;
    for (long unsigned i = 0; i < v.size(); i++) {
        if (v[i] > max) max = v[i];
    }
    return max;
}

int main () {
    int n; std::cin >> n;

    int num = 0;
    while (n > 0) {
        int d = max_digit(n);
        n -= d;
        num++;
    }
    
    std::cout << num << std::endl;
}