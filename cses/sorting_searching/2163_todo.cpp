#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>

template<typename Key, typename Compare = std::less<>>
using ordered_set = __gnu_pbds::tree<Key, __gnu_pbds::null_type, Compare, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;


int main () {
    int n; std::cin >> n;
    int k; std::cin >> k;
    
    ordered_set<int> s;
    for (int i = 0; i < n; i++) {
        s.insert(i + 1);
    }

    int p = k % n;
    while (!s.empty()) {
        int r = *s.find_by_order(p);
        s.erase(r);
        if (!s.empty()) {
            p = (p + k) % s.size();
        }
        std::cout << r << ' ';
    }
    std::cout << std::endl;

}