#include <bits/stdc++.h>

class node {
public:
    int start, end;
    int value;
    std::shared_ptr<node> left;
    std::shared_ptr<node> right;
    node(int start, int end, const std::vector<int>& arr);
    int find_min(int l, int r);
    ~node();
};

node::node(int start, int end, const std::vector<int>& arr): start(start), end(end) {   
    if (start == end) {
        this->value = arr[start];
        this->left = nullptr;
        this->right = nullptr;
    }
    else {
        int mid = (start + end) / 2;
        this->left = std::make_shared<node> (start, mid, arr);
        this->right = std::make_shared<node> (mid + 1, end, arr);
        this->value = std::min(this->left->value, this->right->value);
    }
}

int node::find_min(int l, int r) {
    if (l == this->start && r == this->end) return this->value;
    else if (l >= this->left->start && r <= this->left->end) 
        return this->left->find_min(l, r);
    else if (l >= this->right->start && r <= this->right->end)
        return this->right->find_min(l, r);
    else {
        int m1 = this->left->find_min(l, this->left->end);
        int m2 = this->right->find_min(this->right->start, r);
        return std::min(m1, m2);
    }
    return 0;
}

node::~node() {
}


class SegTree {
public:
    std::shared_ptr<node> root;
    SegTree(const std::vector<int>& arr);
    ~SegTree();
};

SegTree::SegTree(const std::vector<int>& arr) {   
    this->root = std::make_shared<node> (0, arr.size() - 1, arr);
}

SegTree::~SegTree() {
}

int main() {
    int n; std::cin >> n;
    int q; std::cin >> q;

    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) std::cin >> arr[i];

    SegTree s(arr);

    for (int i = 0; i < q; i++) {
        int a; std::cin >> a;
        int b; std::cin >> b;
        std::cout << s.root->find_min(a - 1, b - 1) << std::endl;
    }

}
