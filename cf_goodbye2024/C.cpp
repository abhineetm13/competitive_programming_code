#include <bits/stdc++.h>

typedef long long ll;

ll f(ll, ll);
ll g(ll, ll);

ll f(ll n, ll k) {
    if (n < k) return 0;
    if (n & 1) {
        return 2*f(n/2, k) + (n/2 + 1) + (n/2 + 1)*g(n/2, k);
    }
    else {
        return 2*f(n/2, k) + (n/2)*g(n/2, k);
    }
}

ll g(ll n, ll k) {
    if (n < k) return 0;
    if (n & 1) {
        return 1 + 2*(g(n/2, k));
    }
    else {
        return 2*g(n/2, k);
    }
}

int main () {
    int t;
    std::cin >> t;

    for (int nTest = 0; nTest < t; nTest++) {
        ll n;
        std::cin >> n;
        ll k;
        std::cin >> k;
        std::cout << f(n, k) << std::endl;
    }
}