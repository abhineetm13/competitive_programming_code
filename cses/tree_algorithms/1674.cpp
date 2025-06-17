#include <bits/stdc++.h>

void recurse(int node, const std::vector<std::vector<int>> &edges, std::vector<int> &subordinates) {
    subordinates[node] = edges[node].size();
    for (int child : edges[node]) {
        recurse(child, edges, subordinates);
        subordinates[node] += subordinates[child];
    }
}

int main () {
    int n; std::cin >> n;

    std::vector<std::vector<int>> edges(n);
    for (int i = 1; i < n; i++) {
        int b;
        std::cin >> b;
        edges[b - 1].push_back(i);
    }

    std::vector<int> subordinates(n, 0);
    recurse(0, edges, subordinates);

    for (int i = 0; i < n; i++) {
        std::cout << subordinates[i] << " ";
    }
    std::cout << std::endl;

}