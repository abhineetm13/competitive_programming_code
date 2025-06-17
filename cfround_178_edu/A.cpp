#include <bits/stdc++.h>

using namespace std;

void solve () {
    int a, b, c;
    cin >> a >> b >> c;
    int s = a + b + c;
    if (s % 3 != 0) {
        cout << "NO" << endl;
        return;
    }
    if (b > s/3) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    return;
}

int main () {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
}
