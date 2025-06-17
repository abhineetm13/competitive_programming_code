#include <bits/stdc++.h>

long long algo (long long n) {
    if (n % 2 == 0) return n / 2;
    else return 3 * n + 1;
}

int main () {
    long long n; std::cin >> n;

    long long next = n;
    std::cout << n << " ";
    if (n == 1) return 0;
    do {
        next = algo(next);
        std::cout << next << " ";
    }
    while (next != 1);

}