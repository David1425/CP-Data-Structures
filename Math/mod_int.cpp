template<typename intType, uint64_t mod>
struct ModInt {
	intType num;
	ModInt(intType val=0) : num(val) {
		while (num < 0) num += mod;
		num %= mod;
	}

	using MI = ModInt<intType,mod>;
	
	template<typename T>
	MI operator = (const T& val) { *this=MI(val); return *this; }
	
	MI inv() {
		MI a = num, x = 1;
		uint64_t b = mod-2;
		while (b > 0) {
			if (b&1) x = x*a;
			a = a*a;
			b >>= 1;
		}
		return x;
	}
	
	MI operator + (const MI& val) { return MI(num+val.num); }
	MI operator - (const MI& val) { return MI(num-val.num); }
	MI operator * (const MI& val) { return MI(num*val.num); }
	MI operator / (const MI& val) { return MI(num*val.inv().num); }
	
	void operator += (const MI& val) { *this = (*this)+val; }
	void operator -= (const MI& val) { *this = (*this)-val; }
	void operator *= (const MI& val) { *this = (*this)*val; }
	void operator /= (const MI& val) { *this = (*this)/val; }
	
	MI& operator ++ () {
		*this += MI(1);
		return *this;
	}
	MI operator ++ (int) {
		auto old = *this;
		operator++();
		return old;
	}
	MI& operator -- () {
		*this -= MI(1);
		return *this;
	}
	MI operator -- (int) {
		auto old = *this;
		operator--();
		return old;
	}
	
	bool operator < (const MI& val) { return num < val.num; }
	bool operator <= (const MI& val) { return num <= val.num; }
	bool operator > (const MI& val) { return num > val.num; }
	bool operator >= (const MI& val) { return num >= val.num; }
	bool operator == (const MI& val) { return num == val.num; }
	bool operator != (const MI& val) { return num != val.num; }
	
	friend istream& operator >> (istream& is, MI& mi) { is >> mi.num; mi=MI(mi.num); return is; }
	friend ostream& operator << (ostream& os, const MI& mi) { os << mi.num; return os; }
};

using mi = ModInt<int64_t, MOD>;
