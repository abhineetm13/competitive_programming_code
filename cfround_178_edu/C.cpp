#include <bits/stdc++.h>

using namespace std;

void solve () {
    int n;
    cin >> n;
    vector<char> arr(n);
    int a_count = 0, b_count = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] == 'A')
            a_count++;
        else
            b_count++;
    }

    if (n == 2) {
        if (arr[0] == 'A') {
            cout << "Alice" << endl;
        }
        else {
            cout << "Bob" << endl;
        }
        return;
    }

    if (arr[0] == 'A' && arr[n-1] == 'A') {
        cout << "Alice" << endl;
        return;
    }

    if (arr[0] == 'B' && arr[n-1] == 'B') {
        cout << "Bob" << endl;
        return;
    }

    if (arr[0] == 'A' && arr[n-1] == 'B') {
        if (b_count > 1) {
            cout << "Bob" << endl;
            return;
        }
        else {
            cout << "Alice" << endl;
            return;
        }
    }

    if (arr[0] == 'B' && arr[n-1] == 'A') {
        if (arr[n-2] == 'A') {
            cout << "Alice" << endl;
            return;
        }
        else {
            cout << "Bob" << endl;
            return;
        }
    }

}

int main () {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
}
