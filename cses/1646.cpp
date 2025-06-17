#include <iostream>
using namespace std;

int main() {
    int n; cin >> n;
    int q; cin >> q;

    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i] ;

    long long sums[n];
    sums[0] = arr[0];
    for (int i = 1; i < n; i++) sums[i] = sums[i - 1] + arr[i];

    for (int i = 0; i < q; i++) {
        int a; cin >> a;
        int b; cin >> b;
        if (a == 1) cout << sums[b - 1];
        else cout << sums[b - 1] - sums[a - 2];
        cout << endl;
    }
}