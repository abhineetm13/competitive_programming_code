#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

void solve () {
    int n;
    cin >> n;
    vector<int> arr(n+1);
    int x;
    int found = 0;
    int prev = -1;
    int diff = -1;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        arr[i] = x;
        if (x % gcd(i, n-i+1) != 0) {
            found = 1;
        }
        if (i == 1) {

        }
        else if (i == 2){
            diff = x - prev;
        }
        else {
            if (x - prev != diff) {
                found = 1;
            }
        }
        prev = x;
    }
    if (found == 1) {
        cout << "NO" << endl;
        return;
    }

    // cout << diff << endl;

    int b = -1;
    for (int i = 1; i <= n; i++) {
        arr[i] -= diff*i;
        if (arr[i] % (n+1) != 0) {
            cout << "NO" << endl;
            return;
        } 
        if (i == 1) {
            b = arr[i] / (n+1);
        }
        else {
            if (b != 0 && b != arr[i]/(n+1)) {
                cout << "NO" << endl;
                return;
            }
        }
    }

    if (b < 0 || (diff + b) < 0) {
        cout << "NO" << endl;
        return;
    }
    
    cout << "YES" << endl;
    return;
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
