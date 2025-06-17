#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve () {
    int n;
    cin >> n;
    vector<ll> arr(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    vector<vector<int>> adj_list(n+1);
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    vector<int> parent(n+1, -1);
    vector<ll> max_alt_sum(n+1, 0);
    vector<ll> min_alt_sum(n+1);
    
    queue<int> q;
    parent[1] = 0;
    max_alt_sum[1] = arr[1];
    min_alt_sum[1] = arr[1];
    q.push(1);
    while(!q.empty()) {
        int top = q.front();
        q.pop();
        for (int n : adj_list[top]) {
            if (parent[n] == -1) {
                parent[n] = top;
                max_alt_sum[n] = max(arr[n], arr[n] - min_alt_sum[top]);
                min_alt_sum[n] = min(arr[n], arr[n] - max_alt_sum[top]);
                q.push(n);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << max_alt_sum[i] << " ";
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