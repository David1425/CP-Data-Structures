struct PHASH {
	template<typename T, typename U>
	size_t operator()(const pair<T,U>&x)const{
		return hash<long long>()(((long long)x.first)^(((long long)x.second)<<32));
	}
};
