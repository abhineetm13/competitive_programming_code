#include <iostream>

int main() {
    int t;
    std::cin >> t;
    for(int nTest=0; nTest < t; nTest++) {
        int n;
        std::cin >> n;
        int min = 1001;
        int max = 0;
        for(int i=0; i<n; i++) {
            int ai;
            std::cin >> ai;
            if (max < ai) max = ai;
            if (min > ai) min = ai;
            // std::cout << max << " " << min << std::endl;
        }
        std::cout << (n-1)*(max-min) << '\n';
    }
}