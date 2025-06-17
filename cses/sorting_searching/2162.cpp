#include <bits/stdc++.h>

int main () {
    int n; std::cin >> n;
    
    std::vector<bool> visited(n, false);
    int num_printed = 0;

    int i = 0;
    while (num_printed < n) {
        while (visited[i]) {
            i++;
            i %= n;
        }
        i++;
        i %= n;
        while (visited[i]) {
            i++;
            i %= n;
        }
        std::cout << i + 1 << " ";
        visited[i] = true;
        num_printed++;
        i++;
        i %= n;
    }
}