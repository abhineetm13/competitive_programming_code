#include <bits/stdc++.h>

using namespace std;

void solve () { 
    string s;
    cin >> s;
    size_t n = s.size();

    size_t count = 0;

    for (size_t i = 0; i < n; i++) {
        if (s[i] == '(') {
            count++;
        }
        else {
            count--;
            if (count == 0 && i > 0 && i < n-1) {
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
    return;
}

int main () {
    int t;
    cin >> t;
    for (int i = 0;  i < t; i++) {
        solve();
    }
}
