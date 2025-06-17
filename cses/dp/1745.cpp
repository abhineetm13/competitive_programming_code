#include <bits/stdc++.h>

int main () {
    int n;
    std::cin >> n;

    std::vector<long long> coins;
    for (int i = 0; i < n; i++) {
        long long coin;
        std::cin >> coin;
        coins.push_back(coin);
    }
    std::sort(coins.begin(), coins.end());

    std::unordered_set<long long> vals;
    for (long long coin : coins) {
        std::unordered_set<long long> new_vals = vals;
        new_vals.insert(coin);
        for (long long val : vals) {
            new_vals.insert(val + coin);
        }
        vals = new_vals;
    }

    std::cout << vals.size() << std::endl;
    std::set<long long> sorted_vals;
    for (long long val : vals) {
        sorted_vals.insert(val);
    }
    for (long long val : sorted_vals) {
        std::cout <<val << ' ';
    }
    
    std::cout << std::endl;
}   
