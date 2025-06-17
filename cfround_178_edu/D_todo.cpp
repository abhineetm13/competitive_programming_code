#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

void build_sieve (vector<int> &sieve) {

}

void solve (vector<ll> &first_n_primes_sums) {
    
}

int main () {
    
    int sieve_len = 6e6;
    vector<int> sieve(sieve_len, 0);
    build_sieve(sieve);
    
    ll sum = 0;
    vector<ll> first_n_primes_sums;
    for (int i = 0; i < sieve_len; i++) {
        if (sieve[i]) {
            sum += (i+2);
            first_n_primes_sums.push_back(sum);
        }
    }

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve(first_n_primes_sums);
    }
}