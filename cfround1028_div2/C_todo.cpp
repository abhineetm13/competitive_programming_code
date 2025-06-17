#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

void solve () {
    int n;
    cin >> n;
    vector<int> arr(n);
    
    cin >> arr[0];
    int arrgcd = arr[0];
    
    for (int i = 1; i < n; i++) {
        cin >> arr[i];
        arrgcd = gcd(arrgcd, arr[i]);
    }

    for (int i = 0; i < n; i++) {
        arr[i] /= arrgcd;
        cout << arr[i] << " ";
    }
    cout << endl;

    vector<vector<int>> dp(n, vector<int> (5000+1, n+1));

    dp[0][arr[0]] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < 5000; j++) {
            dp[i][j] = dp[i-1][j];
        }
        for (int j = 1; j <= 5000; j++) {
            dp[i][gcd(j, arr[i])] = min(dp[i][gcd(j, arr[i])], min(dp[i-1][gcd(j, arr[i])], dp[i-1][j]+1));
        }
        dp[i][arr[i]] = 1;
    }

    for (int i =0; i < n; i++) {
        for (int j = 1; j <= 30; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    int min_size = dp[n-1][1];
    cout << (min_size - 1) + (n - 1) << endl;

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
