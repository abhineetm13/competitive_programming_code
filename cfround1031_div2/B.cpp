#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

void solve () {
    int w, h, a, b;
    cin >> w >> h >> a >> b;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    if (x1 > x2) {
        swap(x1, x2);
        swap(y1, y2);
    }

    if (x1 < x2 && y2 > y1 - b && y2 < y1 + b) {
        int t = x2 - (x1 + a);
        if (t%a == 0) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
        return;
    }
    if (x1 < x2 && (y2 >= y1+b || y2 <= y1 - b)) {
        int t1 = x2 - (x1+a);
        int t2 = y2 - (y1+b);
        if (t1%a == 0 || t2 % b == 0) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
        return;
    }

    if (x1 == x2) {
        if (y1 > y2) {
            int t = y1 - (y2+b);
            if (t%b == 0) {
                cout << "YES" << endl;
            } 
            else {
                cout << "NO" << endl;
            }
            return;
        }
        else {
            int t = y2 - (y1+b);
            if (t%b == 0) {
                cout << "YES" << endl;
            } 
            else {
                cout << "NO" << endl;
            }
            return;
        }
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
