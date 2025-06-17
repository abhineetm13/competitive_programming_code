#include <bits/stdc++.h>

using namespace std;

void solve () {
    int n;
    cin >> n;

    int first;
    cin >> first;
    first = abs(first);

    int num_greater = 0;
    for (int i = 0; i < n - 1; i++) {
        int ai;
        cin >> ai;
        if (first < abs(ai)) {
            num_greater++;
        }
    }

    if (num_greater < (n-1)/2) {
        cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl;
    }

}

int main () {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
}
