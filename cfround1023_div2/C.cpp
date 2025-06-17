#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

ll INF = 2e12;

ll max_subarray_sum (vector<ll> arr) {
    ll max_suffix_sum = -INF;
    ll max_subarray_sum = -INF;

    for (size_t i = 0; i < arr.size(); i++) {
        max_suffix_sum = max(arr[i] + max_suffix_sum, arr[i]);
        max_subarray_sum = max(max_subarray_sum, max_suffix_sum);
    }

    return max_subarray_sum;
}

void solve () {
    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    string s;
    cin >> s;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    ll last_zero_idx = -1;
    for (ll i = 0; i < n; i++) {
        if (s[i] == '0') {
            arr[i] = -INF;
            last_zero_idx = i;
        }
    }

    ll m = max_subarray_sum(arr);
    if (m > k) {
        cout << "No" << endl;
        return;
    }

    if (last_zero_idx == -1) {
        if (m != k) {
            cout << "No" << endl;
            return;
        }
        else {
            cout << "Yes" << endl;
            for (ll i = 0; i < n; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
            return;
        }
    }

    cout << "Yes" << endl;
    
    ll b=0, c=0;

    for (ll i = 0; i < last_zero_idx; i++) {
        b = max(arr[i] + b, arr[i]);
    }
    b = max(b, 0LL);

    for (ll i = n - 1; i > last_zero_idx; i--) {
        c = max(arr[i] + c, arr[i]);
    }
    c = max(c, 0LL);

    arr[last_zero_idx] = k - b - c;
    
    for (ll i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

}

int main () {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
}
