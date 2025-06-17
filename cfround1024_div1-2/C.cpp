#include <bits/stdc++.h>

using namespace std;

void solve () {
    int n;
    cin >> n;

    int arr[n][n];

    int currx = n / 2;
    int curry = n / 2;
    int step = 1;

    int j = 0;
    for (int i = 0; i < n; i++) {
        for (;j < i*i + i + 1; j++) {
            arr[currx][curry] = j;
            currx += step;
        }
        currx -= step;
        curry -= step;
        for (; j < i*i + 2*i + 1; j++) {
            arr[currx][curry] = j;
            curry -= step;
        }
        step = -1 * step;
    }

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            cout << arr[x][y] << " ";
        }
        cout << endl;
    }

}

int main () {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
}
