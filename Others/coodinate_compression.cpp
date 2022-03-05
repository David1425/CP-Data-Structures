template<typename T>
unordered_map<T, int> ccomp(vector<T> &vec, int start) {
    sort(all(vec));
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    int len = vec.size();
    unordered_map<T, int> um;
    for (int i = 0; i < len; i++) {
        um[vec[i]] = start+i;
    }
    return um;
}
