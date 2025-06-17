#include <iostream>
#include <vector>
#include <unordered_set> // it is faster with <unordered_set> than <set>

int find(std::vector<int> &parent, int i) {
    if (parent[i] == i) return i;
    int result = find(parent, parent[i]);
    parent[i] = result;
    return result;
}   

int set_union(std::vector<int> &parent, int i, int j) {
    int irep = find(parent, i);
    // std::cout << "irep: " << irep << std::endl;
    int jrep = find(parent, j);
    // std::cout << "jrep: " << jrep << std::endl;
    if (irep != jrep) {
        parent[irep] = jrep;
        return irep;
    }
    else return -1;
}

int main() {
    int n; std::cin >> n;
    int m; std::cin >> m;

    std::vector<int> parent(n);
    std::unordered_set<int> reps;
    for(int i = 0; i < n; i++) {
        parent[i] = i;
        reps.insert(i);
    }

    for(int i = 0; i < m; i++) {
        // std::cout << i << std::endl;
        int e1, e2;
        std::cin >> e1 >> e2;
        int rep = set_union(parent, e1-1, e2-1);
        if (rep != -1) {
            reps.erase(rep);
        }
    }
    std::cout << reps.size() - 1 << std::endl;
    std::vector<int> reps_vec;
    for(int i : reps) {
        reps_vec.push_back(i);
    }
    for(int i = 0; i < reps_vec.size() - 1; i++) {
        std::cout << reps_vec[i] + 1 << " " << reps_vec[i+1] + 1 << std::endl;
    }
}