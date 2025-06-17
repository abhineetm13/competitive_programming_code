#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m, p, q;
    cin >> n >> m >> p >> q;

    if (n % p != 0) {
        cout << "YES" << endl;
    }
    else {
        if (m == n / p * q) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }

}

int main () {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
}
