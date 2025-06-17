#include <bits/stdc++.h>

void bfs(const std::vector<std::vector<int>> &edges, std::vector<int> &parent, int n) {
    std::queue<int> q;
    q.push(0);
    parent[0] = -2;

    while (!q.empty()) {
        int next = q.front();
        // std::cerr << next << std::endl;
        q.pop();
        for (int ngh : edges[next]) {
            // std::cerr << ngh << std::endl;
            if (parent[ngh] == -1) {
                parent[ngh] = next;
                q.push(ngh);
                if (ngh == n - 1) return;
            }
        }
    }
    return;
}

int main() {
    int n; std::cin >> n;
    int m; std::cin >> m;

    std::vector<std::vector<int>> edges(n);
    for(int i = 0; i < m; i++) {
        int e1, e2;
        std::cin >> e1 >> e2;
        edges[e1-1].push_back(e2-1);
        edges[e2-1].push_back(e1-1);
    }

    std::vector<int> parent(n, -1);
    bfs(edges, parent, n);
    // std::cerr << "hi" << std::endl;
    if (parent[n - 1] == -1) {
        std::cout << "IMPOSSIBLE" << std::endl;
    } 
    else {
        std::stack<int> s;
        int top = n - 1;
        while (parent[top] != -2) {
            s.push(top);
            top = parent[top];
            // std::cerr << top << std::endl;
        }
        s.push(0);
        std::cout << s.size() << std::endl;
        while (!s.empty()) {
            std::cout << s.top() + 1 << " ";
            s.pop();
        }
    }
}