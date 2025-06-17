#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

void solve () {
    int x;
    cin >> x;
    cout << 2*int(log2(x)) + 3 << endl;
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        solve();
    }
}
