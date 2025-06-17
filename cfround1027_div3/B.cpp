#include <bits/stdc++.h>

using namespace std;

void solve () {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int zerocount = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            zerocount++;
        }
    }
    int onecount = n - zerocount;

    if (min(zerocount, onecount) < n/2 - k) {
        cout << "NO" << endl;
        return;
    }

    onecount -= (n/2 - k);
    zerocount -= (n/2 - k);
    if (zerocount %2 != 0 || onecount%2 != 0) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
}

int main () {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
}