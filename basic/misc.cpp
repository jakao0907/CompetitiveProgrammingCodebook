編譯參數：-std=c++14 -Wall -Wshadow (-fsanitize=undefined)

#ifdef LOCAL    // =========== Local ===========
void dbg() { cerr << '\n'; }
template<class T, class ...U> void dbg(T a, U ...b) { cerr << a << ' ', dbg(b...); } 
template<class T> void org(T l, T r) { while (l != r) cerr << *l++ << ' '; cerr << '\n'; } 
#define debug(args...) (dbg("#> (" + string(#args) + ") = (", args, ")"))
#define orange(args...) (cerr << "#> [" + string(#args) + ") = ", org(args))
#else            // ======== OnlineJudge ========
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define debug(...) ((void)0)
#define orange(...) ((void)0)
#endif
template<class T> bool chmin(T &a, T b) { return b < a and (a = b, true); }
template<class T> bool chmax(T &a, T b) { return b > a and (a = b, true); } 
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());
int randint(int lb, int ub)
{ return uniform_int_distribution<int>(lb, ub)(gen); }

#define SECs ((double)clock() / CLOCKS_PER_SEC)

struct KeyHasher {
	size_t operator()(const Key& k) const {
		return k.first + k.second * 100000;
}	};
typedef unordered_map<Key,int,KeyHasher> map_t;

__builtin_popcountll    //換成二進位有幾個1
__builtin_clzll         //返回左起第一個1之前0的個數
__builtin_parityll      //返回1的個數的奇偶性
__builtin_mul_overflow(a,b,&h) //回傳a*b是否溢位
