ll sum_odd_1_to_n(ll num) { // from 1 : N
  long long res = (num + 1) / 2;
  long long finalRes = res * res;
  return finalRes;
}
ll sum_even_1_to_n(ll num) {
  num /= 2;
  long long  res = (num * (num + 1));
  return res;
}
ll sumoddrange(ll l, ll r) { // from l : r
  ll res1 = sum_odd_1_to_n(r);
  ll res2 = sum_odd_1_to_n(l - 1);
  ll ans = res1 - res2;
  return ans;

}
ll sumevenrange(ll l, ll r) { // from l : r
  ll p = (r * (r + 1) / 2);
  ll res1 = p - sum_odd_1_to_n(r);
  ll q = (l * (l + 1) / 2);
  ll res2 = q - sum_odd_1_to_n(l);
  ll res = res1 - res2;
  return res;
}
ll number_of_odd(ll l, ll r) {
  return (r - l + 1) - (r / 2 - (l - 1) / 2);
}
ll number_of_even(ll l, ll r) {
  ll numbers_in_range = (r - l) + 1;
  ll even;
  if (l % 2 == 0 && r % 2 == 0)even = ceil(numbers_in_range * 1.0 / 2);
  else  even = numbers_in_range / 2;
  return even;
}
ll Xor(ll n) {
  ll x = n % 4;
  if (x == 0)return n;
  if (x == 1)return 1;
  if (x == 2)return n + 1;
  else if (x == 3)return 0;
}
