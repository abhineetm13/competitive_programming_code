#include <bits/stdc++.h>

class SegNode {
public:
    long long value;
    int start, end;
    std::shared_ptr<SegNode> left;
    std::shared_ptr<SegNode> right;

    SegNode(const std::vector<long long>& arr, int start, int end);
    void update_value(int index, long long val);
    long long find_sum (int s, int e);
};

SegNode::SegNode(const std::vector<long long>& arr, int start, int end): start(start), end(end) {
    if (start == end) {
        this->value = arr[start];
        this->left = nullptr;
        this->right = nullptr;
    }
    else {
        int mid = (start + end) / 2;
        this->left = std::make_shared<SegNode> (arr, start, mid);
        this->right = std::make_shared<SegNode> (arr, mid + 1, end);
        this->value = this->left->value + this->right->value;
    }
}

void SegNode::update_value(int index, long long val) {
    if (this->start == index && this->start == this->end) {
        this->value = val;
    }
    else {
        if (index >= this->left->start && index <= this->left->end) {
            this->left->update_value(index, val);
        } 
        else if (index >= this->right->start && index <= this->right->end) {
            this->right->update_value(index, val);
        }
        this->value = this->left->value + this->right->value;
    }
}

long long SegNode::find_sum (int s, int e) {
    if (this->start > s || this->end < e) return -1;
    if (this->start == s && this->end == e) return this->value;
    else if (this->left->start <= s && this->left->end >= e) 
        return this->left->find_sum(s, e);
    else if (this->right->start <= s && this->right->end >= e) 
        return this->right->find_sum(s, e);
    else return this->left->find_sum(s, this->left->end) + this->right->find_sum(this->right->start, e);
}


void dfs_nonrec (const std::vector<int>& values, 
    const std::vector<std::vector<int>>& neighbours, 
    std::vector<long long>& traversal_array, std::map<int, int>& init_to_final, 
    std::map<int, int>& init_to_altern, std::vector<bool>& visited) {

    std::stack<int> s;
    s.push(0);

    while (!s.empty()) {
        int index = s.top();
        if (!visited[index]) {
            visited[index] = true;
            traversal_array.push_back(values[index]);
            init_to_final.emplace(index, traversal_array.size() - 1);

            for (int i : neighbours[index]) {
                if (!visited[i]) {
                    s.push(i);
                }
            }
        }
        else {
            s.pop();
            traversal_array.push_back(-values[index]);
            init_to_altern.emplace(index, traversal_array.size() - 1);
        }
    }
}

int main () {
    int n; std::cin >> n;
    int q; std::cin >> q;

    std::vector<int> values(n);

    for (int i = 0; i < n; i++) {
        std::cin >> values[i];
    }

    std::vector<std::vector<int>> neighbours(n);

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        std::cin >> a >> b;
        neighbours[a - 1].push_back(b - 1);
        neighbours[b - 1].push_back(a - 1);
    }

    std::vector<long long> traversal_array;
    std::map<int, int> init_to_final;
    std::map<int, int> init_to_altern;
    std::vector<bool> visited(n, false);

    // // std::cout << "hi" << std::endl;

    dfs_nonrec(values, neighbours, traversal_array, init_to_final, init_to_altern, visited);

    // // std::cout << "hii" << std::endl;

    // // for (int i : traversal_array) {
    // //     std::cout << i << " ";
    // // }
    // // std::cout << std::endl;

    // // for (auto i : init_to_final) {
    // //     std::cout << i.first << " " << i.second << std::endl;
    // // }

    SegNode r(traversal_array, 0, traversal_array.size() - 1);

    for (int i = 0; i < q; i++) {
        int mode; std::cin >> mode;
        if (mode == 1) {
            int s; std::cin >> s;
            long long x; std::cin >> x;

            r.update_value(init_to_final[s - 1], x);
            r.update_value(init_to_altern[s - 1], -x);

            // std::cout << "1: " << r.value << std::endl;
        }
        else if (mode == 2) {
            int s; std::cin >> s;
            std::cout << r.find_sum(0, init_to_final[s - 1]) << std::endl;
            // break;
        }
    }

}