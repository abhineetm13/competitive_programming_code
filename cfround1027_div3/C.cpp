#include <bits/stdc++.h>

using namespace std;

void solve () {
    int n;
    cin >> n;
    int prev = -1, curr;
    vector<int> arr;
    for (int i = 0; i < n; i++) {
        cin >> curr;
        if (curr != prev) {
            arr.push_back(curr);
            prev = curr;
        }
    }

    size_t l = arr.size();

    int num_chains = 0;
    int chain_length = 0;
    prev = arr[0];
    for (size_t i = 0; i < l; i++) {
        if (arr[i] > prev+1) {
            num_chains += (chain_length + 1) / 2;
            chain_length = 0;
        }
        chain_length++;
        prev = arr[i];
    }
    num_chains += (chain_length + 1) / 2;
    cout << num_chains << endl;
}

int main () {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
}