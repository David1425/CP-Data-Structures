struct suffix_array {
    string s;
    int k, x;
    
    vector<int> ind, val;
    int size;
    
    void build(string str) {
        s = str+"$";
        vector<pair<char, int>> vec(size);
        for (int i = 0; i < size; i++) {
            vec[i] = {s[i], i};
        }
        sort(vec.begin(), vec.end());
        
        ind[0] = vec[0].second;
        val[ind[0]] = 0;
        for (int i = 1; i < size; i++) {
            ind[i] = vec[i].second;
            val[ind[i]] = val[ind[i-1]];
            if (vec[i].first != vec[i-1].first) val[ind[i]]++;
        }
        
        vector<pair<pair<int, int>, int>> a(size);
        
        k = 0;
        int l = log2(size);
        while (k <= l) {
            x = 1 << k;
            for (int i = 0; i < size; i++) a[i] = {{val[i], val[(i+x)%size]}, i};
            sort(a.begin(), a.end());
            ind[0] = a[0].second;
            val[ind[0]] = 0;
            for (int i = 1; i < size; i++) {
                ind[i] = a[i].second;
                if (a[i-1].first != a[i].first) val[ind[i]]=val[ind[i-1]]+1;
                else val[ind[i]] = val[ind[i-1]];
            }
            k++;
        }
    }
    
    suffix_array(int n) : size(n+1), ind(n+1), val(n+1) {}
    suffix_array(string str) : s(str), size(int(str.size())+1), ind(int(str.size())+1), val(int(str.size())+1) { build(str); }
    
    string getSuffix(int i) { return s.substr(ind[i], size-ind[i]); }
};
