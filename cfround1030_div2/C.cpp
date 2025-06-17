#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

void process(int x, multiset<int> & powset, multiset<int> & bin_len, int & ans) {
    int ind = 0;
    while(x > 0) {
        if (x % 2 == 0) {
            powset.insert(ind);
        }
        else {
            ans++;
        }
        x >>= 1;
        ind++;
    }
    bin_len.insert(ind);
}

void solve () {
    int n;
    cin >> n;
    ll k;
    cin >> k;
    vector<int> arr(n);
    int ans = 0;
    multiset<int> powset;
    multiset<int> bin_len;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        process(arr[i], powset, bin_len, ans);
    }

    // cout << "first" << ans << " " << powset.size() << " " << bin_len.size() << endl;

    while (k > 0 && !powset.empty()) {
        auto m1 = powset.begin();
        auto m2 = bin_len.begin();
        int m = min(*m1, *m2);
        if (m == *m1) {
            powset.erase(m1);
        }
        else {
            bin_len.insert(*m2 + 1);
            bin_len.erase(bin_len.begin());
        }
        if (m == 0) {
            if (k > 0) {
                k--;
                ans++;
            }
        }
        else if (k >= (1<<m)) {
            k -= (1<<m);
            ans++;
        }
        
        else {
            break;
        }
    }

    while (k > 0) {
        auto m2 = bin_len.begin();
        int m = *m2;
        // cout << k << " " << m << " " << ((ll)1<<m) << endl;
        bin_len.erase(m2);
        bin_len.insert(m+1);
        if (m == 0) {
            if (k > 0) {
                k--;
                ans++;
            }
            else {
                break;
            }
        }
        else if (k >= (ll)((ll)1<<m)) {
            k -= (ll)((ll)1<<m);
            ans++;
        }
        else {
            break;
        }
    }

    cout << ans << endl;


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
