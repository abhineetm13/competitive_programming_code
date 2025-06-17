#include <bits/stdc++.h>

using namespace std;

int main () {
    int t;
    cin >> t;

    for (int nTest = 0; nTest < t; nTest++) {
        int n;
        cin >> n;
        int done = 0;
        int num_zeros = 0;
        int prev = 1, curr = 1;
        for (int i = 0; i < n; i++) {
            prev = curr;
            cin >> curr;
            // cout << curr << endl;
            if (curr == 0) {
                num_zeros++;
            }
            if (prev == 0 && curr == 0 && !done) {
                cout << "YES" << endl;
                done = 1;
            }
        }
        if (done) {
            continue;
        }
        if (num_zeros == 0) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}
