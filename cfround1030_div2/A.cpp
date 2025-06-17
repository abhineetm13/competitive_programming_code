#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

void solve () {
    int n;
    cin >> n;
    int k;
    cin >> k;

    for (int i = 0; i < k; i++) {
        cout << "1";
    }
    for (int i = k; i < n; i++) {
        cout << "0";
    }
    cout << endl;


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
