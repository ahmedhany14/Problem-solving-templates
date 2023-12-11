template < typename type = int, const int base = 0 > struct Lazy_segment_tree {

private:
  struct node {
    type val ;
    node(type V = 0) : val(V) {}
  };

  int size;
  node treedefault;
  type lazydefault;
  vector<node> tree;

  vector<type>lazy;
  vector<bool> islazy;

  node lazy_megre(const node & a ,type b){
    node ret;

    ret.val = a.val + b;

    return ret;
  }

  node merge(const node &a,const node &b) {
    node ret;

    ret.val = a.val + b.val;

    return ret;
  }

  void propagate(int i , int l ,int r) {

    if(!islazy[i]) return;

    // if mn |  mx | gcd | something like that don't multiply in (r - l + 1)
    tree[i] = lazy_megre(tree[i], lazy[i] * (r - l + 1));

    if(l != r){
      lazy[2 * i] += lazy[i];
      lazy[2 * i + 1] += lazy[i];

      islazy[2 * i] = islazy[2 * i + 1] = 1;
    }

    lazy[i] = lazydefault, islazy[i] = 0;
  }

  void propagate(int i , int l ,int r, type val) {

    // if mn |  mx | gcd | something like that don't multiply in (r - l + 1)
    tree[i] = lazy_megre(tree[i], val * (r - l + 1));

    if(l != r){

      lazy[2 * i] += val;
      lazy[2 * i + 1] += val;

      islazy[2 * i] = islazy[2 * i + 1] = 1;
    }
  }

  void build(const vector <type>&v, int i, int l, int r){
    if(base ? l >= v.size() : l > v.size()) return;
    if(r == l) {
      tree[i].val = v[l - !base];

    }

    else {

      int m = (r + l) / 2;
      build(v, 2 * i, l, m);
      build(v, 2 * i + 1, m + 1, r);

      tree[i] = merge(tree[2 * i], tree[2 * i + 1]);
    }

  }

  void update(int s, int e, type val, int i, int l, int r) {

    propagate(i, l, r);

    if (l >= s && r <= e)
      return propagate(i, l, r, val);

    if (l > e || r < s)
      return;

    int mid = (l + r) / 2;
    update(s, e, val, 2 * i, l, mid);
    update(s, e, val, 2 * i + 1, mid + 1, r);
    tree[i] = merge(tree[2 * i], tree[2 * i + 1]);
  }
  node query(int s, int e, int i, int l, int r){
    propagate(i, l, r);

    if(l >= s && r <= e) {
      return tree[i];
    }

    if(l > e || r < s) {
      return treedefault;
    }

    int mid = (r + l) / 2;
    return merge(query(s, e, 2 * i, l, mid), query(s, e, 2 * i + 1, mid + 1, r));
  }
public:
  Lazy_segment_tree(int n, vector<type> &v) {
    size = 1, lazydefault = 0, treedefault = node(0);
    while (size < n) size *= 2;

    tree = vector<node>(2 * size, treedefault);

    lazy = vector <type> (size * 2, lazydefault);

    islazy = vector <bool> (size * 2, false);

    build(v, 1, 1, size);
  }
  node query(int l ,int r) { return query(l, r, 1, 1, size); }

  void update(int l ,int r, type val) { update(l, r, val, 1, 1, size); }

};
