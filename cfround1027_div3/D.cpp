#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

pair<pair<ll, ll>, pair<ll, ll>> combine(pair<pair<ll, ll>, pair<ll, ll>> p1, pair<pair<ll, ll>, pair<ll, ll>> p2) {
    return {{min(p1.first.first, p2.first.first), min(p1.first.second, p2.first.second)}, {max(p1.second.first, p2.second.first), max(p1.second.second, p2.second.second)}};
}

struct seg_node {
    shared_ptr<seg_node> lchild;
    shared_ptr<seg_node> rchild; 
    int left, right;
    ll minx, maxx, miny, maxy;

    seg_node(vector<pair<ll, ll>> &arr, int l, int r): left(l), right(r) {
        if (l == r) {
            this->minx = arr[l].first;
            this->maxx = this->minx;
            this->miny = arr[l].second;
            this->maxy = this->miny;
            this->lchild = NULL;
            this->rchild = NULL;
        }
        else {
            int mid = (l + r) / 2;
            this->lchild = make_shared<seg_node>(arr, l, mid);
            this->rchild = make_shared<seg_node>(arr, mid+1, r);
            this->minx = min(this->lchild->minx, this->rchild->minx);
            this->miny = min(this->lchild->miny, this->rchild->miny);
            this->maxx = min(this->lchild->maxx, this->rchild->maxx);
            this->maxy = min(this->lchild->maxy, this->rchild->maxy);
        }
    }

    pair<pair<ll, ll>, pair<ll, ll>> query (int l, int r) {
        if (this->left == this->right) {
            return {{this->minx, this->miny}, {this->maxx, this->maxy}};
        }
        int mid = (this->left + this->right) / 2;
        if (r <= mid) {
            return this->lchild->query(l, r);
        }
        if (l > mid) {
            return this->rchild->query(l, r);
        }
        auto p1 = this->lchild->query(l, mid);
        auto p2 = this->rchild->query(mid+1, r);
        return combine(p1, p2);
    }

};

void solve () {
    int n;
    cin >> n;

    vector<pair<ll, ll>> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    if (n == 1) {
        cout << 1 << endl;
        return;
    }

    vector<pair<pair<ll ,ll>, pair<ll, ll>>> prefix_vals(n+1);
    vector<pair<pair<ll ,ll>, pair<ll, ll>>> suffix_vals(n+1);

    prefix_vals[0] = {{LONG_LONG_MAX, LONG_LONG_MAX}, {LONG_LONG_MIN, LONG_LONG_MIN}};
    suffix_vals[n] = {{LONG_LONG_MAX, LONG_LONG_MAX}, {LONG_LONG_MIN, LONG_LONG_MIN}};

    for (int i = 0; i < n; i++) {
        prefix_vals[i+1] = combine(prefix_vals[i], {{arr[i].first, arr[i].second}, {arr[i].first, arr[i].second}});
        suffix_vals[n-1-i] = combine(suffix_vals[n-i], {{arr[n-i-1].first, arr[n-i-1].second}, {arr[n-i-1].first, arr[n-i-1].second}});
    }

    // for (int i = 0; i < n; i++) {
    //     cout << suffix_vals[i].first.first << " " << suffix_vals[i].second.first << endl;
    // }

    ll min_area = LONG_LONG_MAX;
    for (int i = 0; i < n; i++) {
        ll dim1, dim2;
        ll area;
        pair<pair<ll, ll>, pair<ll, ll>> val = combine(prefix_vals[i], suffix_vals[i+1]);
        
        dim1 = (val.second.first - val.first.first + 1);
        dim2 = (val.second.second - val.first.second + 1);
        area = dim1*dim2;
        if (area == n-1) {
            area += min(dim1, dim2);
        }
        // cout << i << " " << dim1 << " " << dim2 << " " << area << endl;
        min_area = min(min_area, area);
    }
    cout << min_area << endl;
}

int main () {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
}
