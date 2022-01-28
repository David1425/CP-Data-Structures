unordered_map<int, int> ccomp(vector<int> &vec, int start) {
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    int len = vec.size();
    unordered_map<int, int> um;
    for (int i = 0; i < len; i++) {
        um[vec[i]] = start+i;
    }
    return um;
}
