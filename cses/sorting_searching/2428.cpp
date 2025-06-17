#include <bits/stdc++.h>

int main () {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    } 

    long long ans = 0;
    std::map<int, int> vals;
    int start = 0, end = 0;
    
    while (end < n) {
        if(vals.find(arr[end]) == vals.end()) vals.insert({arr[end], 1});
        else vals[arr[end]] += 1;
        end++;
        // std::cerr << start << ' ' << end << ' ' << vals.size() << std::endl;
        if ((int)vals.size() > k) { // end - start > 1
            ans += (end - start - 1);
            if (vals[arr[start]] == 1) vals.erase(arr[start]);
            else vals[arr[start]] -= 1;
            start += 1;
            end--;
            if (vals[arr[end]] == 1) vals.erase(arr[end]);
            else vals[arr[end]] -= 1;
        }
        if (end == n && (int)vals.size() <= k) {
            // std::cerr << start << " hi\n";
            ans += (long long)(n - start)*(long long)(n - start + 1) / 2; 
            break;
        }
    }

    std::cout << ans << std::endl;
}   