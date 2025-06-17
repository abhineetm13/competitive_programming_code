// done, but need to study policy-based data structures
// and binary indexed tree

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

template<typename Key, typename Compare = std::less<>>
using ordered_set = __gnu_pbds::tree<Key, __gnu_pbds::null_type, Compare, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;


int main () {
    int n; std::cin >> n;
    
    std::set<std::pair<std::pair<int, int>, int>> s;
    for (int i = 0; i < n; i++) {
        std::pair<int, int> p;
        std::cin >> p.first >> p.second;
        p.second *= -1;
        s.insert({p, i});
    }

    std::vector<int> ans1 (n, 0);
    auto iter = std::prev(s.end());

    ordered_set<std::pair<int, int>> s1;
    s1.insert({iter->first.second, iter->second});
    for (int i = 1; i < n; i++) {
        iter--;
        ans1[iter->second] = s1.size() - s1.order_of_key({iter->first.second, -1});
        s1.insert({iter->first.second, iter->second});
    }

    for (int i = 0; i < n; i++) 
        std::cout << ans1[i] << " ";
    std::cout << std::endl;

    std::vector<int> ans2 (n, 0);
    iter = s.begin();

    ordered_set<std::pair<int, int>> s2;
    s2.insert({iter->first.second, iter->second});
    for (int i = 1; i < n; i++) {
        iter++;
        ans2[iter->second] = s2.order_of_key({iter->first.second, n});
        s2.insert({iter->first.second, iter->second});
    }

    for (int i = 0; i < n; i++) 
        std::cout << ans2[i] << " ";
    std::cout << std::endl;
}