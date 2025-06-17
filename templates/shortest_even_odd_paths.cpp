/**
 * Code from Codeforces round 1025 div2 Problem D
 * 
 * Contains code to find shortest even-length and shortest 
 * odd-length path from a point to all other points in a graph
 * 
 */

#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m, l;
    cin >> n >> m >> l;

    vector<vector<int>> adj_list(n+1);

    int odd_min = INT_MAX;
    int total = 0;

    for (int i = 0; i < l; i++) {
        int ai;
        cin >> ai;
        if (ai % 2 == 1 && ai < odd_min) {
            odd_min = ai;
        }
        total += ai;
    }

    int odd_max, even_max;

    if (total % 2 == 1) {
        odd_max = total;
        even_max = total - odd_min;
    }
    else {
        even_max = total;
        odd_max = total - odd_min;
    }

    for (int i = 0; i < m; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        adj_list[n1].push_back(n2);
        adj_list[n2].push_back(n1);
    }

    vector<int> even_len(n+1, -1);
    vector<int> odd_len(n+1, -1);
    even_len[1] = 0;

    queue<int> even_q;
    queue<int> odd_q;

    even_q.push(1);
    while (!even_q.empty() || !odd_q.empty()) {
        while (!even_q.empty()) {
            int top = even_q.front();
            even_q.pop();
            for (int ngh : adj_list[top]) {
                if (odd_len[ngh] == -1) {
                    odd_len[ngh] = even_len[top] + 1;
                    odd_q.push(ngh);
                }
            }
        }

        while (!odd_q.empty()) {
            int top = odd_q.front();
            odd_q.pop();
            for (int ngh : adj_list[top]) {
                if (even_len[ngh] == -1) {
                    even_len[ngh] = odd_len[top] + 1;
                    even_q.push(ngh);
                }
            }
        }

    }

    // cout << odd_max << " : " << even_max << endl;
    for (int i = 1; i <= n; i++) {
        // cout << odd_len[i] << " " << even_len[i] << endl;
        if ((odd_len[i] >= 0 && odd_len[i] <= odd_max) || (even_len[i] >= 0 && even_len[i] <= even_max)) {
            cout << "1";
        }
        else {
            cout << "0";
        }
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
