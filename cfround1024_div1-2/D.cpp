#include <bits/stdc++.h>

using namespace std;

int num_inversions_parity(vector<int>& perm, int start, int end) {

    int num_inv_parity = 0;

    if (start == end) {
        return num_inv_parity;
    }
    
    int mid = (start + end) / 2;
    num_inv_parity += num_inversions_parity(perm, start, mid);
    num_inv_parity %= 2;
    num_inv_parity += num_inversions_parity(perm, mid + 1, end);
    num_inv_parity %= 2;

    vector<int> merged(end - start + 1);
    int p = 0, p1 = start, p2 = mid + 1;
    while (p1 <= mid && p2 <= end) {
        if (perm[p1] < perm[p2]) {
            merged[p] = perm[p1];
            num_inv_parity += p2 - (mid + 1);
            num_inv_parity %= 2;
            p++;
            p1++;
        }
        else {
            merged[p] = perm[p2];
            p++;
            p2++;
        }
    }

    while (p1 <= mid) {
        merged[p] = perm[p1];
        num_inv_parity += p2 - (mid + 1);
        num_inv_parity %= 2;
        p++;
        p1++;
    }

    while (p2 <= end) {
        merged[p] = perm[p2];
        p++;
        p2++;
    }

    memcpy(&perm[start], &merged[0], sizeof(int) * (end - start + 1));

    return num_inv_parity % 2;
}

void solve () {
    int n;
    cin >> n;
    vector<int> perm;
    vector<int> odd;
    vector<int> even;

    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        perm.push_back(x);
        if (i%2 == 0) even.push_back(x);
        else odd.push_back(x); 
    }

    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());

    int init_inv_parity = num_inversions_parity(perm, 0, n - 1);

    vector<int> final_perm(n);
    int eveni = 0, oddi = 0;
    for (int i = 0; i < n; i++) {
        if (i%2 == 0) {
            final_perm[i] = even[eveni];
            eveni++;
        }
        else {
            final_perm[i] = odd[oddi];
            oddi++;
        }
    }

    vector<int> final_temp = final_perm;
    int final_inv_parity = num_inversions_parity(final_temp, 0, n-1);
    if (final_inv_parity != init_inv_parity) {
        swap(final_perm[n-3], final_perm[n-1]);
    }

    for (int i = 0; i < n; i++) {
        cout << final_perm[i] << " ";
    }
    cout << endl;

}

int main () {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
}
