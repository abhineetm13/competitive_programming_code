#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

void solve () {
    int n;
    cin >> n;
    vector<int> arr(n);
    map<int, int> freq;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        freq[arr[i]]++;
    }

    int max  = -1, nextmax = -1;
    for (auto itr = freq.begin(); itr != freq.end(); itr++) {
        if (itr->second >= 4) {
            for (int j = 0; j < 4; j++)
                cout << itr->first << " ";
            cout << endl;
            return;
        }
        if (itr->second >= 2) {
            nextmax = max;
            max = itr->first;
        }
    }
    int mindiff = INT_MAX, nextmindiff = INT_MAX;


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
