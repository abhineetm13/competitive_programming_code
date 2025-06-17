#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

void solve () {
    int n;
    cin >> n;
    cout << 2*n - 1 << endl;
    for (int i = 0; i < n - 1; i++) {
        cout << i+1 << " " << 1 << " "  << i+1 << endl;
        cout << i+1 << " " << i+2 << " " << n << endl;
    }
    int i = n - 1;
    cout << i+1 << " " << 1 << " "  << i+1 << endl;

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
