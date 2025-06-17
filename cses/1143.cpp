#include <bits/stdc++.h>

class SegNode {
public:
    int value;
    int start, end;
    std::shared_ptr<SegNode> left;
    std::shared_ptr<SegNode> right;

    SegNode(const std::vector<int>& arr, int start, int end);
    int find_first(int needed);
    void update_value(int index, int needed);
};

SegNode::SegNode(const std::vector<int>& arr, int start, int end): start(start), end(end) {
    if (start == end) {
        this->value = arr[start];
        this->left = nullptr;
        this->right = nullptr;
    }
    else {
        int mid = (start + end) / 2;
        this->left = std::make_shared<SegNode> (arr, start, mid);
        this->right = std::make_shared<SegNode> (arr, mid + 1, end);
        this->value = std::max(this->left->value, this->right->value);
    }
}

int SegNode::find_first(int needed) {
    if (this->value < needed) return -1;
    if (this->start == this->end) return this->start;
    if (this->left->value >= needed) return this->left->find_first(needed);
    else return this->right->find_first(needed);
}

void SegNode::update_value(int index, int needed) {
    if (this->start == this->end) {
        this->value -= needed;
    }
    else {
        if (index >= this->left->start && index <= this->left->end) {
            this->left->update_value(index, needed);
        } 
        else if (index >= this->right->start && index <= this->right->end) {
            this->right->update_value(index, needed);
        }
        this->value = std::max(this->left->value, this->right->value);
    }
}

int main () {
    int n; std::cin >> n;
    int m; std::cin >> m;

    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) std::cin >> arr[i];

    SegNode s(arr, 0, n - 1);

    for (int i = 0; i < m; i++) {
        int r; std::cin >> r;
        int index = s.find_first(r);
        std::cout << index + 1 << " ";
        if (index != -1) s.update_value(index, r);
    }
}