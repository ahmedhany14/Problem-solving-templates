vc<ll> constructlis(vc<ll>vec) { // get lis if i take element of vec[i]
	vector<ll> L, lis(vec.size());
	for (int i = 0; i < vec.size(); ++i) {
		const ll num = vec[i];
		ll pos = lower_bound(L.begin(), L.end(), num) - L.begin();
		if (pos == L.size())L.push_back(num);
		else L[pos] = num;
		lis[i] = pos + 1;
	}
	return lis;
}
