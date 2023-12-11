template < typename T = ll > struct mohamed_algorithm {
  struct query {
    int l, r, query_ind, block_ind;
    query(int L = 0, int R = 0, int query_ind = 0) {
      l = L - 1, r = R - 1, this->query_ind = query_ind;
    }
    bool operator<(const query &q) const {
      return (block_ind < q.block_ind) || (block_ind == q.block_ind && r < q.r);
    }
  };
  int curr_l, curr_r, n, m, SQRT;
  vector<query> queries;
  vector<T> answers, v, freq , prefix;
  ll ret;
  mohamed_algorithm(int sz = 0, int qsz = 0) {
    curr_l = 1, curr_r = 0, ret = 0, n = sz, m = qsz, SQRT = sqrtl(n);
    queries.resize(m), answers.resize(m), v.resize(n);
    freq.resize(5e6 + 5);
  }
  void setblocks() {
    for (int i = 0; i < m; i++) queries[i].block_ind = queries[i].l / SQRT;
  }
  void Get_Data() {
    for(int i = 0 ;i < n ;i++)
      cin >> v[i];
    for (int i = 0, l, r; i < m ; i++) {
      cin >> l >> r;
      queries[i] = query(l, r , i);
    }
    setblocks();
  }

  void add(int idx) {
    
    
  }
  void remove(int idx) {
    
  
  }
  void set_range(query q) {
    while (curr_l < q.l) remove(curr_l++);
    while (curr_l > q.l) add(--curr_l);
    while (curr_r < q.r) add(++curr_r);
    while (curr_r > q.r) remove(curr_r--);
  }
  void Process() {
    sort(all(queries));
    for (int i = 0; i < m; i++) {
      set_range(queries[i]);
      answers[queries[i].query_ind] = ret;
    }
  }
  void print() {
    for (int i = 0; i < m; i++) cout << answers[i] << '\n';
  }
};
