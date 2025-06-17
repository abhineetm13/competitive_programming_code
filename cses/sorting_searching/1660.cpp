#include <bits/stdc++.h>

int main () {
    int n;
    std::cin >> n;
    int x;
    std::cin >> x;

    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    int start = 0, end = 0;
    int curr_sum = arr[0];
    int num_x = 0;
    while (end < n) {
        if (curr_sum == x) {
            num_x++;
            if (start != end) {
                curr_sum -= arr[start];
                start++;
            }
            else {
                end++;
                if (end < n) curr_sum += arr[end];
            }
        }
        else if (curr_sum > x) {
            if (start != end) {
                curr_sum -= arr[start];
                start++;
            }
            else {
                end++;
                if (end < n) curr_sum += arr[end];
            }
        }
        else {
            end++;
            if (end < n) curr_sum += arr[end];
        }
    }

    std::cout << num_x << std::endl;
}