#include <bits/stdc++.h>

#define MOD 998244353

typedef long long ll;
using namespace std;


void solve (vector<int> & precomp) {
    int n;
    cin >> n;

    vector<int> p(n), max_ind_p(n, 0), q(n), max_ind_q(n, 0);
    cin >> p[0];
    for (int i = 1; i < n; i++) {
        cin >> p[i];
        if (p[i] > p[max_ind_p[i-1]]) {
            max_ind_p[i] = i;
        }
        else {
            max_ind_p[i] = max_ind_p[i-1];
        }
    }
    cin >> q[0];
    for (int i = 1; i < n; i++) {
        cin >> q[i];
        if (q[i] > q[max_ind_q[i-1]]) {
            max_ind_q[i] = i;
        }
        else {
            max_ind_q[i] = max_ind_q[i-1];
        }
    }

    // for (int i = 0; i < n; i++) {
    //     cout << max_ind_p[i] << " " << max_ind_q[i] << endl;
    // }

    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        if (p[max_ind_p[i]] == q[max_ind_q[i]]) {
            if (p[i - max_ind_q[i]] > q[i - max_ind_p[i]]) {
                ans[i] = (precomp[q[max_ind_q[i]]] + precomp[p[i - max_ind_q[i]]]) % MOD;
            }
            else {
                ans[i] = (precomp[p[max_ind_p[i]]] + precomp[q[i - max_ind_p[i]]]) % MOD;
            }
        }
        else if (p[max_ind_p[i]] > q[max_ind_q[i]]) {
            ans[i] = (precomp[p[max_ind_p[i]]] + precomp[q[i - max_ind_p[i]]]) % MOD;
        }
        else {
            ans[i] = (precomp[q[max_ind_q[i]]] + precomp[p[i - max_ind_q[i]]]) % MOD;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> precomp(1e5, 0);
    precomp[0] = 1;
    for (int i = 1; i < 1e5; i++) {
        precomp[i] = precomp[i-1] * 2;
        precomp[i] %= MOD;
    }

    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        solve(precomp);
    }
}
