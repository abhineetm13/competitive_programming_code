#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

void solve () {
    // cout << "HI" << endl;
    int n;
    cin >> n;
    vector<int> arr(n);
    set<int> vals;
    map<int, stack<int>> positions;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        vals.insert(arr[i]);
        positions[arr[i]].push(i);
    }
    // cout << "hi" << endl;

    int count = 0;
    int min_pos = n;
    int pos;
    while (min_pos != 0) {
        for (int x : vals) {
            while(!positions[x].empty() && positions[x].top() >= min_pos) {
                positions[x].pop();
            }
        }

        for (int x : vals) {
            if (positions[x].empty()) {
                positions.erase(x);
            }
        }
        set<int> y = vals;
        for (int x : y) {
            if (positions.find(x) == positions.end()) {
                vals.erase(x);
            }
        }
        // cout << positions[5].size() << endl;
        // cout << "HI " << positions.size() << endl;

        for (auto itr = positions.begin(); itr != positions.end(); itr++) {
            if (itr->second.empty()) {
                continue;
            }
            // cout << itr->first << " ";
            pos = itr->second.top();
            min_pos = min(min_pos, pos);
            itr->second.pop();
        }
        // cout << min_pos << endl;;
       
        count++;
    }

    cout << count << endl;

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