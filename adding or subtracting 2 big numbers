bool com(string s, string t){
  int n = s.size(), m = t.size();
  if (n < m) return 0;
  if (m < n) return 0;
  for (int i = 0; i < n; i++) {
    if (s[i] < t[i]) return 1;
    else if (s[i] > t[i])return 0;
  }
  return 0;
}
string sub(string s, string t){
  if (com(s, t)) swap(s, t);
  string res = "";
  int n = s.size(), m = t.size();
  reverse(all(s));
  reverse(all(t));
  int carry = 0;
  for (int i = 0; i < m; i++) {
    int sub = ((s[i] - '0') - (t[i] - '0') - carry);
    if (sub < 0) sub = sub + 10 ,carry = 1;
    else carry = 0;
    res.push_back(sub + '0');
  }
  for (int i = m; i < n; i++) {
    int sub = ((s[i] - '0') - carry);
    if (sub < 0)  sub = sub + 10,carry = 1;
    else carry = 0;
    res.push_back(sub + '0');
  }
  while (res.back() == '0')res.pop_back();
  reverse(all(res));
  return res;
}
string add(string a, string b) {
  if (a.length() > b.length()) swap(a, b);
  string str = "";
  int n = a.length(), m = b.length();
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  int carry = 0;
  for (int i=0; i< n; i++) {
    int sum = ((a[i] - '0') + (b[i] - '0') + carry);
    str.push_back(sum % 10 + '0');
    carry = sum / 10;
  }
  for (int i= n; i < m; i++) {
    int sum = ((b[i] - '0') + carry);
    str.push_back(sum % 10 + '0');
    carry = sum / 10;
  }
  if (carry) str.push_back(carry+'0');
  reverse(str.begin(), str.end());
  return str;
}
