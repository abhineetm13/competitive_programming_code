#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

struct state {
    int ba;
    int ca;
    int cb;
    int cba;
    int bca;

    state(int i1, int i2, int i3, int i4, int i5) : 
        ba(i1), ca(i2), cb(i3), cba(i4), bca(i5) {}
};

void solve () {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;

    stack<int> cba;
    stack<int> bca;
    state init(0, 0, 0, 0, 0);
    int freeba = 0, freeca = 0;
    char x, y;
    for (int i = 0; i < q; i++) {
        cin >> x >> y;
        if (x == 'b' && y == 'a') {
            init.ba++;
            if (cba.empty()) {
                freeba++;
            }
            else {
                init.cba++;
                cba.pop();
            }
        }
        if (x == 'c' && y == 'a') {
            init.ca++;
            if (bca.empty()) {
                freeca++;
            }
            else {
                init.bca++;
                bca.pop();
            }
        }
        if (x == 'c' && y == 'b') {
            init.cb++;
            cba.push(1);
        }
        if (x == 'b' && y == 'c') {
            bca.push(1);
        }
    }

    for (int i = 0; i < n; i++) {
        if (s[i] == 'b' && freeba > 0) {
            s[i] = 'a';
            freeba--;
        }
        if (s[i] == 'c' && freeca > 0) {
            s[i] = 'a';
            freeca--;
        }
    }

    vector<vector<state>> dp; 

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
