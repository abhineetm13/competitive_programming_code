#include <bits/stdc++.h>

using namespace std;

void solve () {
    int n, k;
    cin >> n >> k;

    int min = INT_MAX, max = 0, max_count = 0, parity = 0;

    
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x % 2 == 1) parity ^= 1;
        if (x < min) min = x;
        if (x == max) {
            max_count++;
        }
        if (x > max) {
            max = x;
            max_count = 1;
        }
    }

    if (max - min > k+1) {
        cout << "Jerry" << endl;
        return;
    }
    if (max - min == k + 1 && max_count > 1) {
        cout << "Jerry" << endl;
        return;
    }
    
    if (parity == 1) {
        cout << "Tom" << endl;
    }
    else {
        cout << "Jerry" << endl;
    }

}

int main () {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
}