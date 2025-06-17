#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

void solve () {
    int n;
    cin >> n;
    vector<ll> arr(n);
    vector<ll> prefix_max(n+1, 0);
    vector<ll> suffix_sum(n+1, 0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        prefix_max[i+1] = max(arr[i], prefix_max[i]);
    }
    for (int i = n-1; i >= 0; i--) {
        suffix_sum[i] = suffix_sum[i+1] + arr[i];
    }

    for (int i = 0; i < n; i++) {
        cout << prefix_max[n-i] + suffix_sum[n-i] << " ";
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
