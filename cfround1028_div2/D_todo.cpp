#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

void solve () {
    int n, q;
    cin >> n >> q;
    vector<int> b(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    vector<int> x(q), y(q), z(q);
    for (int i = 0; i < q; i++) {
        cin >> x[i] >> y[i] >> z[i];
    }

    vector<int> low = b;

    for (int i = q - 1; i >= 0; i--) {
        low[x[i]] = max(low[x[i]], low[z[i]]);
        low[y[i]] = max(low[y[i]], low[z[i]]);
    }

    vector<int> c = low;
    for (int i = 0; i < q; i++) {
        c[z[i]] = min(c[x[i]], c[y[i]]);
    }

    for (int i = 1; i <= n; i++) {
        if (c[i] != b[i]) {
            cout << -1 << endl;
            return;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << low[i] << " ";
    }
    cout << endl;

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
