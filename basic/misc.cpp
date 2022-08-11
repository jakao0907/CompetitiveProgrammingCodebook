編譯參數：-std=c++14 -Wall -Wshadow (-fsanitize=undefined)

void _col(int i) { string _[3] = {"\e[0m", "\e[1;33m", "\e[1;32m"}; cerr << _[i]; }
void dbg() { cerr << '\n'; }
template<class T, class ...U> void dbg(T a, U ...b) { cerr << a << ' ', dbg(b...); } 
template<class T> void org(T l, T r) { while (l != r) cerr << *l++ << ' '; cerr << '\n'; } 
#define debug(args...) (_col(1), dbg("(" + string(#args) + ") = (", args, ")"), _col(0))
#define orange(args...) (_col(2), cerr << "[" + string(#args) + ") = ", org(args), _col(0))

mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());
int randint(int lb, int ub)
{ return uniform_int_distribution<int>(lb, ub)(gen); }

#define SECs ((double)clock() / CLOCKS_PER_SEC)
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

struct KeyHasher {
	size_t operator()(const Key& k) const {
		return k.first + k.second * 100000;
}	};
typedef unordered_map<Key,int,KeyHasher> map_t;

__builtin_popcountll    //換成二進位有幾個1
__builtin_clzll         //返回左起第一個1之前0的個數
__builtin_parityll      //返回1的個數的奇偶性
__builtin_mul_overflow(a,b,&h) //回傳a*b是否溢位
