ll lisnlogn(vector<ll>& v) {
	if (v.size() == 0) return 0;
	vector<ll> tail(v.size(), 0);
	int length = 1; tail[0] = v[0];
	for (int i = 1; i < v.size(); i++) {
		auto b = tail.begin(), e = tail.begin() + length;
		auto it = lower_bound(b, e, v[i]);
		if (it == tail.begin() + length) tail[length++] = v[i];
		else *it = v[i];
	}
	return length;
}
