vc<ll> nextGreaterelement(vector <ll>v) {
  int n = v.size();
  vector<ll> nxt(n, n);
  stack<int> stk;
  for (int i = 0; i < n; i++) {
    while (!stk.empty() && v[stk.top()] < v[i])
      nxt[stk.top()] = i, stk.pop();
    stk.push(i);
  }
  return nxt;
}
vc<ll> next_smaller_element(vector <ll> nums) {
  int n = nums.size();
  vector<ll> nxt(n, n);
  stack<int> stk;
  for (int i = 0; i < n; i++) {
    while (!stk.empty() && nums[stk.top()] > nums[i])
      nxt[stk.top()] = i, stk.pop();
    stk.push(i);
  }
  return nxt;
}
vc<ll> prevGreaterelement(vector < ll > v) {
  int n = v.size();
  vector<ll> prv(n, -1);
  stack<int> stk;
  for (int i = n - 1; i >= 0; i--) {
    while (!stk.empty() && v[stk.top()] <= v[i])
      prv[stk.top()] = i, stk.pop();
    stk.push(i);
  }
  return prv;
}
vc<ll> prev_smaller_element(vector <ll> v) {
  int n = v.size();
  vector<ll> prv(n, -1);
  stack<int> stk;
  for (int i = n - 1; i >= 0; i--) {
    while (!stk.empty() && v[stk.top()] >= v[i])
      prv[stk.top()] = i, stk.pop();
    stk.push(i);
  }
  return prv;
}
