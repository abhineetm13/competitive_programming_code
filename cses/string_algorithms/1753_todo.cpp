
#include <bits/stdc++.h>

void kmp (std::vector<int>& positions, std::string s, std::string p) {
    
}

int main () {
    std::string s;
    std::cin >> s;
    std::string p;
    std::cin >> p;

    std::vector<int> positions;
    kmp(positions, s, p);
    std::cout << positions.size() << std::endl;

}