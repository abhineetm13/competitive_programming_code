#include <bits/stdc++.h>

long long insert_delete(std::multiset<long long> &lesser, std::multiset<long long> &greater, long long median,
    long long &sum_lesser, long long &sum_greater, long long val_i, long long val_d) {   
        
        bool i_lesser = true;
        bool d_lesser = true;
        
        if (lesser.find(val_d) != lesser.end()) {
            lesser.erase(lesser.find(val_d));
            sum_lesser -= val_d;
        }
        else if (greater.find(val_d) != greater.end()) {
            greater.erase(greater.find(val_d));
            sum_greater -= val_d;
            d_lesser = false;
        }
        else {
            // val_d is the median
            median = *greater.begin();
            sum_greater -= *greater.begin();
            greater.erase(greater.find(median));
            d_lesser = false;
        }

        if (val_i <= median) {
            lesser.insert(val_i);
            sum_lesser += val_i;
        }
        else {
            greater.insert(val_i);
            sum_greater += val_i;
            i_lesser = false;
        }

        if (i_lesser && !d_lesser) {
            greater.insert(median);
            sum_greater += median;
            median = *(lesser.rbegin());
            sum_lesser -= median;
            lesser.erase(lesser.find(median));
        }
        else if (!i_lesser && d_lesser) {
            lesser.insert(median);
            sum_lesser += median;
            median = *(greater.begin());
            sum_greater -= median;
            greater.erase(greater.find(median));
        }

        int n = lesser.size() + greater.size();
        return (sum_lesser + sum_greater - n * median);
}

int main () {
    long long n, k;
    std::cin >> n >> k;
    std::vector<long long> arr(n);
    for (long long i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    std::multiset<long long> lesser, greater;
    long long median;
    long long sum_lesser = 0, sum_greater = 0;

    std::vector<long long> b;
    for (int i = 0; i < k; i++) {
        b.push_back(arr[i]);
    }
    std::sort(b.begin(), b.end());
    median = b[(k - 1) / 2];
    for (int i = 0; i < (k - 1) / 2; i++) {
        lesser.insert(b[i]);
        sum_lesser += b[i];
    }
    for (int i = (k + 1) / 2; i < k; i++) {
        greater.insert(b[i]);
        sum_greater += b[i];
    }
    std::cout << sum_lesser + sum_greater + median - k * median << " ";

    for (int i = k; i < n; i++) {
        std::cout << insert_delete(lesser, greater, median, sum_lesser, 
            sum_greater, arr[i], arr[i - k]) << " ";
    }
    std::cout << std::endl;

}