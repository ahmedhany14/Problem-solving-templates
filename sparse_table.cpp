int const LOG = 30 , maxn = 2e5 + 10;
int sp[maxn][LOG];
int a[maxn];

void sparse_table(int n) {
  for(int i = 0 ;i < n ;i++) // length 1 is the same element
    sp[i][0] = a[i];
  for (int k = 1; k < LOG; k++) // length of (2 power k)
    for (int j = 0; j + (1 << k) - 1 < n; j++)
      sp[j][k] = min(sp[j][k - 1], sp[j + (1 << (k - 1))][k - 1]);
}

int query(int l , int r) {
  int k = 0;
  int len = r - l + 1;
  while ((1 << (k + 1)) <= len)k++; // nearest power of two for the length
  // 0 or 1 based ???
  //--l;
  //--r;
  return min(sp[l][k], sp[r - (1 << k) + 1][k]);
}
