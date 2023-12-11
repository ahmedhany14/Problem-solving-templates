int const LOG = 30 , maxn = 2e5 + 10;
int sp[N][LOG];

// binary lifting
void sparse_table(int n) {
  for(int u = 2 ;u <= n ;u++) // length 1 is the same element
    sp[u][0] = parent[u];
  for (int k = 1; k < LOG; k++) // length of (2 power k)
    for (int u = 2; u <= n; u++)
      sp[u][k] = sp[sp[u][k - 1]][k - 1];
}

int kth_ancestor (int node ,int k){
  for(int i = 0 ; i < LOG ;i++){
    if(k & (1 << i))
      node = sp[node][i];
  }
  return node;
}
