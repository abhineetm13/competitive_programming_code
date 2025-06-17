#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

void solve () {
    int k, a, b, x, y;
    cin >> k >> a >> b >> x >> y;
    int ans = 0;
    int mindelta = min(x, y);
    if (mindelta == x) {
        if (k >= a) {
            ans += (k-a)/x + 1;
            k -= x*ans;
        }
        if (k >= b)
            ans += (k-b)/y + 1;
        cout << ans << endl;
        return;
    }
    else {
        if (k >= b) {
            ans += (k-b)/y + 1;
            k -= y*ans;
        }
        if (k >= a)
            ans += (k-a)/x + 1;
        cout << ans << endl;
        return;
    }
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
