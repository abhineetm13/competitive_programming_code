#include <bits/stdc++.h>

int main () {
    int x; std::cin >> x;
    int n; std::cin >> n;

    std::set<int> s;
    std::vector<int> inputs(n);

    s.insert(0);
    s.insert(x);
    for (int i = 0; i < n; i++) {
        int p; std::cin >> p;
        s.insert(p);
        inputs[i] = p;
    }

    int max = 0;
    std::vector<int> ans(n);
    for (auto i = s.begin(); i != s.end(); i++) {
        if (*std::next(i) - *i > max) 
            max = *std::next(i) - *i;
    }

    ans[n - 1] = max;
    for (int i = n - 1; i >= 1; i--) {
        auto iter = s.find(inputs[i]);
        int l = *std::next(iter) - *std::prev(iter);
        s.erase(iter);
        if (l > ans[i]) ans[i - 1] = l;
        else ans[i - 1] = ans[i];
    }

    for (int i = 0; i < n; i++) {
        std::cout << ans[i] << " ";
    }
    std::cout << std::endl;
}