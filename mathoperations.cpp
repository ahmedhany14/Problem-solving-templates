const int MOD = 998244353 ;
int add(int x , int y) {
  int z = x + y ;
  if(z >= MOD) z -= MOD ;
  return z ;
}
int sub(int x , int y) {
  int z = x - y;
  if (z < 0) z += MOD;
  return z;
}
int mul(int x , int y) { return (x * 1ll * y) % MOD; }
int binmod(int base , int power) {
  if (power == 0) return 1;
  int x = binmod(base, power / 2);
  x = mul(x, x);
  if (power & 1) x = mul(x, base);
  return x;
} 
int inv_mod(int x) { return binmod(x, MOD - 2);}
int Div(int x , int y) { return mul(x, inv_mod(y)); }
