/**
 * Code from Codeforces round 1026 div2 problem C
 * 
 * Contains some functions for intervals
 */

#include <bits/stdc++.h>

using namespace std;

pair<int, int> int_intersection (pair<int, int> a, pair<int, int> b) {
    return {max(a.first, b.first), min(a.second, b.second)};
}

pair<int, int> int_union (pair<int, int> a, pair<int, int> b) {
    return {min(a.first, b.first), max(a.second, b.second)};
} 

void solve () {
    int n;
    cin >> n;
    vector<int> blank_idxs;
    vector<int> d(n);
    vector<int> cum_d(n+1);
    cum_d[0] = 0;
    for (int i = 0; i < n; i++) {
        cin >> d[i];
        if (d[i] == -1) {
            blank_idxs.push_back(i);
            cum_d[i+1] = cum_d[i];
        }
        else {
            cum_d[i+1] = cum_d[i] + d[i];
        }
    }
    // for (int i = 0; i <= n; i++) {
    //     cout << cum_d[i] << " ";
    // }
    // cout << endl;
    size_t count = blank_idxs.size();

    vector<pair<int, int>> obstacles(n);
    int li, ri;
    for (int i = 0; i < n; i++) {
        cin >> li >> ri;
        obstacles[i] = {li - cum_d[i+1], ri - cum_d[i+1]};
    }

    vector<pair<int, int>> bounds(count + 1, {INT_MIN, INT_MAX});
    vector<pair<int, int>> bounds_0(count), bounds_1(count);
    int i = n - 1;
    for (size_t j = count; i >= 0 && j >= 0; i--) {
        bounds[j] = int_intersection(bounds[j], obstacles[i]);
        if (bounds[j].second < bounds[j].first) {
            cout << -1 << endl;
            return;
        }
        if (j > 0 && i == blank_idxs[j-1]) {
            bounds_0[j-1] = bounds[j];
            bounds_1[j-1] = {bounds[j].first - 1, bounds[j].second - 1};
            bounds[j-1] = {bounds[j].first - 1, bounds[j].second};
            j--;
        }   
    }

    if (0 < bounds[0].first || 0 > bounds[0].second) {
        cout << -1 << endl;
        return;
    }

    vector<int> final_vals(count);
    int cum_sum = 0;
    for (size_t i = 1; i < count + 1; i++) {
        if ((cum_sum + 1 < bounds[i].first) || (cum_sum > bounds[i].second)) {
            cout << -1 << endl;
            return;
        }
        if (cum_sum == bounds[i].first - 1) {
            // cout << cum_sum << " : " << bounds[i].first << " ; " << bounds[i].second << endl;
            final_vals[i-1] = 1;
            cum_sum++;
        }
        else {
            final_vals[i-1] = 0;
        }
    }

    for (size_t i = 0; i < count; i++) {
        d[blank_idxs[i]] = final_vals[i];
    }

    for (int i = 0; i < n; i++) {
        cout << d[i] << " ";
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
