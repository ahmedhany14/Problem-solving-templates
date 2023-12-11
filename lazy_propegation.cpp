template < typename T = int, const int base = 0 > struct lazy_propegation {
  struct node {
    T val;
    node(T V = 0) : val(V) {}
    node operator=(const T rhs) {
      val = rhs;
      return *this;
    }
  };

  int size;
  T lazydefault, treedefault;
  vector <node> tree;
  vector<T> lazy;
  vector<bool> islazy;
  void intial(int n){
    size = 1;
    treedefault = 0, lazydefault = 0;
    while(size <= n) size *= 2;
    tree = vector <node> (size * 2, treedefault);
    lazy = vector <T> (size * 2, lazydefault);
    islazy = vector <bool> (size * 2, false);
  }
  lazy_propegation(int n, const vector <T> &v) {
    intial(n);
    build(v);
  }
  T lazyOperation(T a, T b){
    return b;
  }
  node operation(const node &a,const node &b){
    return a.val + b.val;
  }
  void propagate(int i, int l, int r){
    if(!islazy[i]) return;
    tree[i] = lazyOperation(tree[i].val, lazy[i] * (r - l + 1));
    if(l != r){
      lazy[2 * i] = lazyOperation(lazy[2 * i], lazy[i]);
      lazy[2 * i + 1] = lazyOperation(lazy[2 * i + 1], lazy[i]);
      islazy[2 * i] = islazy[2 * i + 1] = 1;
    }
    lazy[i] = lazydefault, islazy[i] = 0;
  }
  void propagate(int i, int l, int r, T val){
    tree[i] = lazyOperation(tree[i].val, val * (r - l + 1));
    if(l != r){
      lazy[2 * i] = lazyOperation(lazy[2 * i], val);
      lazy[2 * i + 1] = lazyOperation(lazy[2 * i + 1], val);
      islazy[2 * i] = islazy[2 * i + 1] = 1;
    }
  }
  void build(const vector <T>&v, int i, int l, int r){
    propagate(i, l, r);
    if(base ? l >= v.size() : l > v.size()) return;
    if(r == l) {
      tree[i] = v[l - !base];
    } else {
      int m = (r + l) / 2;
      build(v, 2 * i, l, m);
      build(v, 2 * i + 1, m + 1, r);
      tree[i] = operation(tree[2 * i], tree[2 * i + 1]);
    }
  }
  void build(const T initval, int i, int l, int r) {
    propagate(i, l, r);
    if (r == l) tree[i] = initval;
    else {
      int m = (r + l) / 2;
      build(initval, 2 * i, l, m);
      build(initval, 2 * i + 1, m + 1, r);
      tree[i] = operation(tree[2 * i], tree[2 * i + 1]);
    }
  }

  void build(const T initval) { build(initval, 1, 1, size); }
  void build(const vector <T>& nums) { build(nums, 1, 1, size); }

  void update(int s, int e, T val, int i, int l, int r) {
    propagate(i, l, r);
    if (l >= s && r <= e) return propagate(i, l, r, val);
    if (l > e || r < s) return;
    int mid = (l + r) / 2;
    update(s, e, val, 2 * i, l, mid);
    update(s, e, val, 2 * i + 1, mid + 1, r);
    tree[i] = operation(tree[2 * i], tree[2 * i + 1]);
  }
  node query(int s, int e, int i, int l, int r){
    propagate(i, l, r);
    if(l >= s && r <= e) return tree[i];
    if(l > e || r < s) return treedefault;
    int mid = (r + l) / 2;
    return operation(query(s, e, 2 * i, l, mid), query(s, e, 2 * i + 1, mid + 1, r));
  }
  void update(int i, T v) { update(i, i, v, 1, 1, size); }// up 1 index
  void update(int l, int r, T v) { update(l, r, v, 1, 1, size); } // up l to r
  node query(int l, int r) { return query(l, r, 1, 1, size); } // query l to r
  node query(int i) { return query(i, i, 1, 1, size); }// // query i
};
