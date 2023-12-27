template < typename type = int , int base = 0 > struct segment_tree {
private:
  struct node {
    type val;
    node(type V = 0) : val(V) {}
  };
  int size;
  node DEFAULT;
  vector<node> tree;
  segment_tree(int n = 0) {
    size = 1, DEFAULT = 0;
    while (size < n) size *= 2;
    tree = vector<node>(2 * size, DEFAULT);
  }
  void build(const vector<type> &v) { build(v, 1, 1, size); }
  node megre(const node &a, const node &b) { return a.val ^ b.val; }
  void build(const vector<type> &v, int idx, int l, int r) {
    if (base ? l >= v.size() : l > v.size())
      return;
    if (r == l)
      tree[idx] = v[l - !base];
    else {
      int mx = (r + l) / 2;
      build(v, 2 * idx, l, mx);
      build(v, 2 * idx + 1, mx + 1, r);
      tree[idx] = megre(tree[2 * idx], tree[2 * idx + 1]);
    }
  }
  void update(int index, type v, int idx, int l, int r) {
    if (r == l) tree[idx] = v;
    else {
      int mid = (r + l) / 2;
      if (index <= mid) update(index, v, 2 * idx, l, mid);
      else update(index, v, 2 * idx + 1, mid + 1, r);
      tree[idx] = megre(tree[2 * idx], tree[2 * idx + 1]);
    }
  }
  node query(int start, int end, int idx, int l, int r) {
    if (l > end || start > r) return DEFAULT;
    if (l >= start && r <= end) return tree[idx];
    int mid = (l + r) / 2;
    return megre(query(start, end, 2 * idx, l, mid),query(start, end, 2 * idx + 1, mid + 1, r));
  }
public:  
  segment_tree(int n, const vector<type> &v) {
    size = 1, DEFAULT = 0;
    while (size < n) size *= 2;
    tree = vector<node>(2 * size, DEFAULT);
    build(v);
  }
  void update(const int index, const type v) { update(index, v, 1, 1, size); }
  node query(const int l, const int r) { return query(l, r, 1, 1, size); }
};
