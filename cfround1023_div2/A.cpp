#include <bits/stdc++.h>

using namespace std;


void solve () {
    int n;
    cin >> n;

    int arr[n];
    cin >> arr[0];
    int arr_gcd = arr[0];
    for (int i = 1; i < n; i++) {
        cin >> arr[i];
        arr_gcd = gcd(arr_gcd, arr[i]);
    }

    int noteq_idx = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] != arr_gcd) {
            noteq_idx = i;
            break;
        }
    }
    if (noteq_idx == -1) {
        cout << "No" << endl;
        return;
    }
    cout << "Yes" << endl;
    for (int i = 0; i < n; i++) {
        if (i == noteq_idx) cout << "1 ";
        else cout << "2 ";
    }
    cout << endl;

}

int main () {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        solve();
    }
}
