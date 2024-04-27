vector<int> prefix_function(string& a){
    int n = (int) a.size();
    vector<int> prefix(n, 0);
    for(int i = 1; i < n; ++i){
        int j = prefix[i - 1];
        while (j > 0 and a[i] != a[j]) j = prefix[j - 1];
        j += (a[i] == a[j]);
        prefix[i] = j;
    }
    return prefix;
}
