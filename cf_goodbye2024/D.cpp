#include <bits/stdc++.h>

#define MOD 998244353 

// found at https://codeforces.com/blog/entry/136455
int qpow (int a, int x = MOD - 2) {
    int res = 1;
	for (; x; x >>= 1, a = 1ll * a * a % MOD) if (x & 1) res = 1ll * res * a % MOD;
	return res;
}

int last_ind(const std::vector<std::pair<int, int>> &v, int start, int end, int n) {
    if (start == end) {
        if (v[start].first == n) return start;
        else return -1;
    }
    int mid = (start + end) / 2;
    if (n > v[mid].first) return last_ind(v, mid + 1, end, n);
    else if (n == v[mid].first) {
        if (n == v[mid + 1].first) return last_ind(v, mid + 1, end, n);
        else return mid;
    } 
    else return last_ind(v, start, mid, n);
} 

int main () {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);

    int t;
    std::cin >> t;

    for (int nTest = 0; nTest < t; nTest++) {
        int n;
        std::cin >> n;
        int q;
        std::cin >> q;
        std::vector<int> a(n, 0), b(n, 0);
        for (int i = 0; i < n; i++) std::cin >> a[i];
        for (int i = 0; i < n; i++) std::cin >> b[i];

        std::vector<std::pair<int, int>> a1(n), b1(n);
        for (int i = 0; i < n; i++) {
            a1[i] = {a[i], i};
            b1[i] = {b[i], i};
        }
        std::sort(a1.begin(), a1.end());
        std::sort(b1.begin(), b1.end());

        std::map<int, int> a_map, b_map;
        long long ans = 1;
        for (int i = 0; i < n; i++) {
            ans *= std::min(a1[i].first, b1[i].first);
            ans %= MOD;
            a_map.insert({a1[i].second, i});
            b_map.insert({b1[i].second, i});
        }
        std::cout << ans << " ";

        for (int i = 0; i < q; i++) {
            int o, x;
            std::cin >> o >> x;
            if (o == 1) {
                int ind = a_map[x - 1];
                int last = last_ind(a1, ind, n - 1, a[x - 1]);
                a_map.at(a1[last].second) = ind;
                a_map.at(x - 1) = last;
                a1[ind].second = a1[last].second;
                a1[last] = {a1[last].first + 1, x - 1};
                a[x - 1]++;
                if (a1[last].first <= b1[last].first) {
                    ans *= qpow(a1[last].first - 1);
                    ans %= MOD;
                    ans *= a1[last].first;
                    ans %= MOD;
                }
            }
            else {
                int ind = b_map[x - 1];
                int last = last_ind(b1, ind, n - 1, b[x - 1]);
                b_map.at(b1[last].second) = ind;
                b_map.at(x - 1) = last;
                b1[ind].second = b1[last].second;
                b1[last] = {b1[last].first + 1, x - 1};
                b[x - 1]++;
                if (b1[last].first <= a1[last].first) {
                    ans *= qpow(b1[last].first - 1);
                    ans %= MOD;
                    ans *= b1[last].first;
                    ans %= MOD;
                }
            }
            std::cout << ans << " ";
        }

        std::cout << '\n';
    }
}