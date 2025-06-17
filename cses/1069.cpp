#include <bits/stdc++.h>

int main () {
    std::string s;
    std::cin >> s;

    int n = s.size();

    int p = 0;
    int lmax = 0;

    int l = 0;
    char curr = s[0];
    while (p < n) {
        if (s[p] == curr) {
            l++;
            p++;
        }
        else {
            curr = s[p];
            l = 0;
        }
        if (l > lmax) lmax = l;
    }
    std::cout << lmax << std::endl;
}