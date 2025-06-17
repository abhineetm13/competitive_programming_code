#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

void solve () {
    // cout << "hi" << endl;
    int n, m, k;
    cin >> n >> m >> k;
    char mine[n][m];
    
    int tot_gold = 0;
    int tot_empty = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mine[i][j];
            if (mine[i][j] == 'g') {
                tot_gold++;
            }
            if (mine[i][j] == '.') {
                tot_empty++;
            }
        }
    }
    // cout << mine[1][0] << endl;
    // cout << "hi" << endl;

    int min_loss = INT_MAX;
    vector<vector<int>> losses(n, vector<int>(m, 0));
    int i = 0, j = 0;
    for (int i1 = max(i - k + 1, 0); i1 < min(i + k, n); i1++) {
        for (int j1 = max(j - k + 1, 0); j1 < min(j+k, m); j1++) {
            if (mine[i1][j1] == 'g') {
                losses[0][0]++;
            }
        }
    }
    // cout << "hi" << endl;
    if (mine[0][0] == '.') {
        min_loss = losses[0][0];
    }
    for (int i = 1; i < n; i++) {
        losses[i][0] = losses[i-1][0];
        int i1 = i - k;
        if (i1 >= 0) {
            for (int j1 = max(j - k + 1, 0); j1 < min(j+k, m); j1++) {
                if (mine[i1][j1] == 'g') {
                    losses[i][0]--;
                }
            }
        }
        // cout << i << " hi" << endl;

        i1 = i + k - 1;
        if (i1 < n) {
            for (int j1 = max(j - k + 1, 0); j1 < min(j+k, m); j1++) {
                if (mine[i1][j1] == 'g') {
                    losses[i][0]++;
                }
            }
        }
        if (mine[i][0] == '.' && losses[i][0] < min_loss) {
            min_loss = losses[i][0];
        }
    }
    // cout << "hi" << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 1; j < m; j++) {
            // cout << i << " hi" << endl;

            losses[i][j] = losses[i][j-1];
            int j1 = j-k;
            if (j1 >= 0) {
                for (int i1 = max(i - k + 1, 0); i1 < min(i + k, n); i1++) {
                    if (mine[i1][j1] == 'g') {
                        losses[i][j]--;
                    }
                }
            }
            j1 = j + k - 1;
            if (j1 < m) {
                for (int i1 = max(i - k + 1, 0); i1 < min(i + k, n); i1++) {
                    if (mine[i1][j1] == 'g') {
                        losses[i][j]++;
                    }
                }
            }
            
            if (mine[i][j] == '.') {
                if (losses[i][j] < min_loss)
                    min_loss = losses[i][j];
            }
        }
    }

    // cout << tot_empty << " " << tot_gold << " " << min_loss << endl;
    cout << tot_gold - min_loss << endl;

}

int main () {
    // cout << "hi\n";

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        solve();
    }
}
