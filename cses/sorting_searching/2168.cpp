#include <bits/stdc++.h>

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

    std::set<int> s1;
    s1.insert(iter->first.second);
    for (int i = 1; i < n; i++) {
        iter--;
        if (iter->first.second <= *std::prev(s1.end())) {
            ans1[iter->second] = 1;
        }
        s1.insert(iter->first.second);
    }

    for (int i = 0; i < n; i++) 
        std::cout << ans1[i] << " ";
    std::cout << std::endl;

    std::vector<int> ans2 (n, 0);
    iter = s.begin();

    std::set<int> s2;
    s2.insert(iter->first.second);
    for (int i = 1; i < n; i++) {
        iter++;
        if (iter->first.second >= *s2.begin()) {
            ans2[iter->second] = 1;
        }
        s2.insert(iter->first.second);
    }

    for (int i = 0; i < n; i++) 
        std::cout << ans2[i] << " ";
    std::cout << std::endl;
}