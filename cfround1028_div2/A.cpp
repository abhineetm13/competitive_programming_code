#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

void solve () {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int min_g = min(a, c);
    int min_f = min(b, d);

    if (min_g >= min_f) {
        cout << "Gellyfish" << endl;
        return;
    }

    cout << "Flower" << endl;

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
