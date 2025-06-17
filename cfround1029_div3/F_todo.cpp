#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

ll MOD = 1e9 + 7;

ll mypow2(int n) {
    ll x = 1;
    for (int i = 0; i < n;i++) {
        x <<= 1;
        x %= MOD; 
    }
    return x;
}

void solve () {
    int n;
    cin >> n;
    vector<vector<int>> adj_list(n+1, vector<int>());
    int u, v;
    for (int i = 0; i < n-1; i++) {
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    vector<int> parent(n+1, -1);
    queue<int> q;
    q.push(1);
    parent[1] = 0;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int n : adj_list[x]) {
            if (parent[n] == -1) {
                parent[n] = x;
                q.push(n);
            }
        }
    }

    vector<vector<int>> children(n+1, vector<int>());
    for (int i = 1; i <= n; i++) {
        children[parent[i]].push_back(i);
    }
    int numleaves = 0;
    int joint = -1;
    for (int i = 1; i <= n; i++) {
        if (children[i].size() == 0) {
            numleaves++;
        }
        if (children[i].size() == 2) {
            joint = i;
        }
    }
    if (numleaves > 2) {
        cout << 0 << endl;
        return;
    }

    if (joint == -1) {
        cout << mypow2(n) << endl;
        return;
    }

    int l1 = 1, l2 = 1;
    int c1 = children[joint][0], c2 = children[joint][1];
    while (children[c1].size() != 0) {
        c1 = children[c1][0];
        l1++;
    }
    while (children[c2].size() != 0) {
        c2 = children[c2][0];
        l2++;
    }

    // cout << l1 << " " << l2 << endl;

    int a = min(l1, l2);
    int b = max(l1, l2);

    ll ans;
    if (a == b) {
        ans = (mypow2(n - 2*a) + mypow2(n - 2*a)) % MOD;
    }

    else ans = (mypow2(n - 2*a - 1) + mypow2(n - 2*a)) % MOD;
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
