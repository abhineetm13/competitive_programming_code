#include <bits/stdc++.h>

int find_rem(int a, int n) {
    int rem = a % n;
    if (rem < 0) {
        rem = (rem + n) % n;
    }
    return rem;
}

int main () {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    std::vector<int> cum_arr(n + 1);
    cum_arr[0] = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
        cum_arr[i + 1] = find_rem(cum_arr[i] + arr[i], n);
    }

    long long num_ans = 0;
    std::vector<int> cum_map(n, 0);
    for (int i = n; i  >= 0; i--) {
        num_ans += cum_map[cum_arr[i]];
        // std::cerr << cum_arr[i] << std::endl;
        cum_map[cum_arr[i] % n] += 1;
    }

    std::cout << num_ans << std::endl;
}