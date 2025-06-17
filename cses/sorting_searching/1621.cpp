#include <bits/stdc++.h>

int main () {
    int n; std::cin >> n;
    std::set<int> s;
    for (int i = 0; i < n; i++) {
        int k;
        std::cin >> k;
        s.insert(k);
    }
    std::cout << s.size() << std::endl;
}