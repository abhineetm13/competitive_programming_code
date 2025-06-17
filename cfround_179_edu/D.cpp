#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

void solve () {
    int n, m;
    cin >> n >> m;
    map<int, stack<int>> classes;
    int ai;
    for (int i = 0; i < m; i++) {
        cin >> ai;
        if (classes.find(ai/100) == classes.end()) {
            classes[ai/100] = stack<int>();
        }
        classes[ai/100].push(ai);
    }

    while (n >= 2) {
        int c1 = prev(classes.end())->second.top();
        prev(classes.end())->second.pop();
        if(prev(classes.end())->second.empty()) {
            classes.erase(prev(classes.end()));
        }

        int c2 = classes.begin()->second.top();
        classes.begin()->second.pop();
        if(classes.begin()->second.empty()) {
            classes.erase(classes.begin());
        }

        for (int i = 0; i < 3; i++) {
            cout << c1 << " " << c2 << " ";
        }
        cout << endl;
        for (int i = 0; i < 3; i++) {
            cout << c2 << " " << c1 << " ";
        }
        cout << endl;

        n -= 2;
    }

    if (n == 1) {
        int c1 = prev(classes.end())->second.top();
        int c2 = classes.begin()->second.top();

        for (int i = 0; i < 3; i++) {
            cout << c2 << " " << c1 << " ";
        }
        cout << endl;
    }

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
