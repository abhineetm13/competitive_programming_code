#include <bits/stdc++.h>

#define int long long

bool poss(const std::vector<int> &cum_arr, int size, int k) {
    int p1 = 0;
    int p2 = 1;
    for (int i = 0; i < k; i++) {
        while (p2 < cum_arr.size() && (cum_arr[p2] - cum_arr[p1]) <= size) {
            p2++;
        }
        if (p2 == cum_arr.size()) {
            return true;
        }
        p1 = p2 - 1;
    }
    return false;
}

int search (const std::vector<int> &cum_arr, int start, int end, int k) {
    if (start == end) {
        return start;
    }
    
    int mid = (start + end) / 2;
    if (poss(cum_arr, mid, k)) {
        return search(cum_arr, start, mid, k);
    }
    else return search(cum_arr, mid + 1, end, k);
}

signed main () {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> arr(n);
    std::vector<int> cum_arr(n + 1);
    cum_arr[0] = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
        cum_arr[i + 1] = cum_arr[i] + arr[i];
    }

    std::cout << search(cum_arr, cum_arr[n] / k, cum_arr[n], k);

    
}