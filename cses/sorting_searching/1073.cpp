#include <bits/stdc++.h>

int search (const std::vector<int>& sizes, int value) {
    int start = 0;
    int end = sizes.size() - 1;

    if (end == -1) return -1;
    if (value >= sizes[end]) return -1;

    while (start < end) {
        int mid = (start + end) / 2;
        if (value < sizes[mid]) {
            end = mid;
        }
        else {
            start = mid + 1;
        }
    }
    return start;
}

int main () {
    int n; std::cin >> n;

    std::vector<int> arr(n);
    int num = 0;
    std::vector<int> sizes;
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
        int min_index_i = -1;
        
        min_index_i = search(sizes, arr[i]);

        if (min_index_i == -1) {
            num++;
            sizes.push_back(arr[i]);
        }
        else {
            sizes[min_index_i] = arr[i];
        }
    }

    std::cout << num << std::endl;
}