#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

void solve () {
    int n;
    cin >> n;
    vector<ll> arr(n);
    ll min_val = LONG_LONG_MAX;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    ll curr = arr[0];
    ll currlen = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] != curr) {
            min_val = min(min_val, curr*(n - currlen));
            curr = arr[i];
            currlen = 1;
        }
        else {
            currlen++;
        }
    }
    min_val = min(min_val, curr*(n - currlen));
    cout << min_val << endl;
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
