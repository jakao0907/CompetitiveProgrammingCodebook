struct BIT{
#define lowbit(x) (x&-x)
	int n;
	vector<long long> a;
	BIT(int _n){
		n = _n;
		a.clear(); a.resize(n+1, 0);
	}
	void update(int x, int v){
		while(x < a.size()){
			a[x] += v;
			x += lowbit(x);
		}
	}
	long long query(int x){
		long long ret = 0;
		while(x){
			ret += a[x];
			x -= lowbit(x);
		}
		return ret;
	}
	long long query(int l, int r){
		return query(r) - query(l-1);
	}
	int kth(int k){
		int x = 0;
		for (int i = 1 << __lg(n); i; i >>= 1){
			if (x + i <= n and k >= a[x + i - 1]){
				x += i;
				k -= a[x - 1];
			}
		}
		return x;
	}
};