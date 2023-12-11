map<char, ll>characters;
deque<char> dp;
ll od = 0, ev = 0;
bool ispal(string a) {
  string b = a;
  reverse(all(b));
  return a == b;
}
char middle_odd_char;
bool can_be_palindrom(string a) {
  for (auto q : a)characters[q]++;
  for (auto a : characters) {
    if (a.second % 2 == 0)ev++;
    else od++,middle_odd_char = a.first;
  }
  return od <= 1;
}
string build_palindrom(string a) {
  if (od)
    while (characters[middle_odd_char])
      dp.push_back(middle_odd_char),characters[middle_odd_char]--;
  for (auto a : characters) {
    bool front = 0, back = 0;
    while (characters[a.first]) {
      if (front)dp.push_front(a.first), front = 0,back = 1;
      else dp.push_back(a.first), front = 1,back = 0;
      characters[a.first]--;
    }
  }
  string ans;
  for (auto a : dp) ans += a;
  return ans;
}
