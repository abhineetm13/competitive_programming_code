#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

void rec(int n, int m, int offx, int offy) {
    if (n == 1 && m == 1) {
        cout << offx + 1 << " " << offy + 1 << endl;
    }
    else if (n == 1) {
        rec(n, m-2, offx, offy+1);
        cout << offx + 1 << " " << offy + 1 << endl;
        cout << offx + 1 << " " << offy + m << endl;
    }
    else if (m == 1) {
        rec(n-2, m, offx+1, offy);
        cout << offx + 1 << " " << offy + 1 << endl;
        cout << offx + m << " " << offy + 1 << endl;
    }
    else if (n == m) {
        rec(n - 2, m - 2, offx + 1, offy + 1);
        cout << offx + n/2 + 1 << " " << offy + 1 << endl;
        cout << offx + n/2 + 1 << " " << offy + m << endl;
        for (int i = 1; i <= (n-2)/2; i++) {
            cout << offx + 1 + n/2 - i << " " << offy + 1 << endl;
            cout << offx + 1 + n/2 - i << " " << offy + m << endl;
            cout << offx + 1 + n/2 + i << " " << offy + 1 << endl;
            cout << offx + 1 + n/2 + i << " " << offy + m << endl;
        }
        cout << offx + 1 << " " << offy + m/2 + 1 << endl;
        cout << offx + n << " " << offy + m/2 + 1 << endl;
        for (int i = 1; i <= m/2; i++) {
            cout << offx + 1 << " " << offy + 1 + m/2 - i << endl;
            cout << offx + n << " " << offy + 1 + m/2 - i << endl;
            cout << offx + 1 << " " << offy + 1 + m/2 + i << endl;
            cout << offx + n << " " << offy + 1 + m/2 + i << endl;
        }
    }
    else if (n > m) {
        rec(n-2, m, offx+1, offy);
        cout << offx + n/2 + 1 << " " << offy + 1 << endl;
        cout << offx + n/2 + 1 << " " << offy + m << endl;
        for (int i = 1; i <= n/2; i++) {
            cout << offx + 1 + n/2 - i << " " << offy + 1 << endl;
            cout << offx + 1 + n/2 - i << " " << offy + m << endl;
            cout << offx + 1 + n/2 + i << " " << offy + 1 << endl;
            cout << offx + 1 + n/2 + i << " " << offy + m << endl;
        }
    }
    else {
        rec(n-2, m, offx, offy+1);
        cout << offx + 1 << " " << offy + m/2 + 1 << endl;
        cout << offx + n << " " << offy + m/2 + 1 << endl;
        for (int i = 1; i <= m/2; i++) {
            cout << offx + 1 << " " << offy + 1 + m/2 - i << endl;
            cout << offx + n << " " << offy + 1 + m/2 - i << endl;
            cout << offx + 1 << " " << offy + 1 + m/2 + i << endl;
            cout << offx + n << " " << offy + 1 + m/2 + i << endl;
        }
    }
}

void solve () {
    int n, m;
    cin >> n >> m;
    rec(n, m, 0, 0);
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
