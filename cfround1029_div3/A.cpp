#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

void solve () {
    int n, x;
    cin >> n >> x;
    int open;
    int firstpos = -1, lastpos = -1;
    for (int i = 0; i < n; i++) {
        cin >> open;
        if (open == 1) {
            if (firstpos == -1) {
                firstpos = i;
            }
            lastpos = i;
        }
    }

    if (x >= (lastpos - firstpos + 1)) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
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
