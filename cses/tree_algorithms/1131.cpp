#include <bits/stdc++.h>

void recurse (int node, const std::vector<std::vector<int>> &edges, std::vector<int> &diam, std::vector<int> &max_to_root, std::vector<bool> &visited) {
    visited[node] = true;

    std::vector<int> children;
    for (int i : edges[node]) {
        if (!visited[i]) {
            children.push_back(i);
        }
    }

    for (int i : children) {
        recurse(i, edges, diam, max_to_root, visited);
    }

    int d1 = 0;
    for (int i : children) {
        if (diam[i] > d1) d1 = diam[i];
    }

    int l1 = -1;
    int l2 = -1;
    for (int i : children) {
        if (max_to_root[i] >= l1) {
            l2 = l1;
            l1 = max_to_root[i];
        }
        else if (max_to_root[i] >= l2) {
            l2 = max_to_root[i];
        }
    }

    int d;
    if (children.size() <= 1) {
        d = std::max(d1, l1 + 1);
    }
    else {
        d = std::max(d1, l1 + l2 + 2);
    }
    diam[node] = d;
    max_to_root[node] = l1 + 1;
    return;
}

int main () {
    int n; std::cin >> n;

    if (n == 1) {
        std::cout << 0 << std::endl;
        return 0;
    }

    std::vector<std::vector<int>> edges(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        std::cin >> a >> b;
        edges[a - 1].push_back(b - 1);
        edges[b - 1].push_back(a - 1);
    }

    int root = 0;
    std::vector<int> diam(n, 0);
    std::vector<int> max_to_root(n, 0);
    std::vector<bool> visited(n, false);

    recurse(root, edges, diam, max_to_root, visited);
    std::cout << diam[0] << std::endl;
}