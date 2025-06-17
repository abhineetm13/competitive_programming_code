#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>

template<typename Key, typename Compare = std::less<>>
using ordered_set = __gnu_pbds::tree<Key, __gnu_pbds::null_type, Compare, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;


int find_median (const ordered_set<std::pair<int, int>> &s, int k) {
    int m;
    if (k % 2 == 0) {
        m = s.find_by_order(k / 2 - 1)->first;
    }
    else {
        m = s.find_by_order((k - 1) / 2)->first;
    }
    // fprintf(stderr, "%d\n", m);
    return m;
}

int main () {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    ordered_set<std::pair<int, int>> s;
    for (int i = 0; i < k; i++) {
        s.insert({arr[i], i});
    }
    std::cout << find_median(s, k) << " ";

    for (int i = k; i < n; i++) {
        s.erase({arr[i - k], i - k});
        s.insert({arr[i], i});
        std::cout << find_median(s, k) << " ";
    }

    std::cout << std::endl;

}
