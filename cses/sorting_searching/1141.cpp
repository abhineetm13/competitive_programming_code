#include <bits/stdc++.h>

int main () {
    int n; std::cin >> n;

    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    int longest = 0;
    int start = 0;
    int end = 0;
    std::set<int> done;

    while (start <= end && end < n) {
        while (end < n && done.find(arr[end]) == done.end()) {
            done.insert(arr[end]);
            end++;
        }
        if (end - start > longest) longest = (end - start);
        done.erase(arr[start]);
        start++;
    }

    std::cout << longest << std::endl;

}