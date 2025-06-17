#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

void solve (vector<int> & fibo) {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int w, l, h;
        cin >> w >> l >> h;
        int maxd = max(w, max(l ,h));
        int mind = min(w, min(l, h));
        if (maxd >= fibo[n] + fibo[n-1] && mind >= fibo[n]) {
            cout << '1';
        }
        else {
            cout << '0';
        }
    }
    cout << endl;
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> fibo(10+1);
    fibo[1] = 1;
    fibo[2] = 2;
    for (int i = 3; i <= 10; i++) {
        fibo[i] = fibo[i-1] + fibo[i-2];
    }

    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        solve(fibo);
    }
}
