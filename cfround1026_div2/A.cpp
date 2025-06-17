#include <bits/stdc++.h>

using namespace std;

void solve () {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int amin = arr[0], amax = arr[n-1];
    if((amax + amin) % 2 == 0) {
        // cout << amin << " : " << amax << endl;
        cout << 0 << endl;
        return;
    }
    int leftce = 0, rightce = 0;
    while (arr[leftce] % 2 == 0) {
        leftce++;
    }
    while (arr[n - 1 - rightce] % 2 == 0) {
        rightce++;
    }
    
    int leftco = 0, rightco = 0;
    while (arr[leftco] % 2 != 0) {
        leftco++;
    }
    while (arr[n - 1 - rightco] % 2 != 0) {
        rightco++;
    }
    int leftc = max(leftce, leftco);
    int rightc = max(rightce, rightco);
    // cout << leftc << " ; " << rightc << endl;
    cout << min(leftc, rightc) << endl;
    return;
}

int main () {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
}