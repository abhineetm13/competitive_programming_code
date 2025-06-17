#include <bits/stdc++.h>

using namespace std;

int sqrt(int n) {
  
    int lo = 1, hi = n;
    
    while(lo < hi) {
        int mid = (hi + lo)/2;
        
        if(mid*mid >= n) {
            hi = mid;
        }
        
        else {
            lo = mid + 1;
        }
    }
    
    return lo;
}

void solve () {
    string s;
    cin >> s;
    int n = 0;
    int pow = 1000;
    for (int i = 0; i < 4; i++) {
        n += pow * (s[i] - '0');
        pow /= 10;
    }

    if (n == 0) {
        cout << "0 0\n";
        return;
    }

    int squareroot = sqrt(n);
    if (squareroot * squareroot != n) {
        cout << -1 << '\n';
        return;
    }
    cout << 0 << " " << squareroot << '\n';
    return;
}

int main () {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
}
