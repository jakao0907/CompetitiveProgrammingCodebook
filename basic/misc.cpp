編譯參數：-std=c++14 -Wall -Wshadow (-fsanitize=undefined)
//check special cases for example (n==1)
//check size  arrays

#include <random>
mt19937 gen(0x5EED);
int randint(int lb, int ub)
{ return uniform_int_distribution<int>(lb, ub)(gen); }

#define SECs ((double)clock() / CLOCKS_PER_SEC)

struct KeyHasher {
	size_t operator()(const Key& k) const {
		return k.first + k.second * 100000;
	}
};
typedef unordered_map<Key,int,KeyHasher> map_t;
__builtin_popcountll	//換成二進位有幾個1