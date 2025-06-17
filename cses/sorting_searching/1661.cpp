#include <bits/stdc++.h>

#define int long long

signed main () {
    int n;
    std::cin >> n;
    int x;
    std::cin >> x;

    std::vector<int> arr(n);
    std::vector<int> cum_arr(n + 1);
    cum_arr[0] = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
        cum_arr[i + 1] = cum_arr[i] + arr[i];
    }

    int num_sum_x = 0;
    std::map<int, int> cum_nums;
    for (int i = n; i >= 0; i--) {
        if (cum_nums.find(cum_arr[i]) == cum_nums.end()) {
            cum_nums[cum_arr[i]] = 1;
        }
        else {
            cum_nums.at(cum_arr[i]) += 1;
        }
        
        if (cum_nums.find(cum_arr[i] + x) != cum_nums.end()) {
            num_sum_x += cum_nums[cum_arr[i] + x];
        }
    }
    if (x == 0) {
        num_sum_x--;
        num_sum_x -= n;
    }

    std::cout << num_sum_x << std::endl;
}