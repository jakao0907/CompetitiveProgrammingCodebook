template<class T>
struct SparseTable{
#define MAXN 500005
#define K 20
    int n;
    T st[K + 1][MAXN];
    T add(T lhs, T rhs){
        return lhs + rhs;
    }
    SparseTable(vector<T> &arr){
        n = arr.size();
        copy(arr.begin(), arr.end(), st[0]);
        for (int i = 1; i <= K; i++)
        for (int j = 0; j + (1 << i) <= n; j++)
            st[i][j] = add(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
    }
    T query(int L, int R){ //assert L <= R
        T ret = st[i][L]; ++L;
        for (int i = K; i >= 0; i--) {
            if ((1 << i) <= R - L + 1) {
                ret = add(ret, st[i][L]);
                L += 1 << i;
            }
        }
        return ret;
    }
    pair<T, int> less_equal(int L, int v){//sum, index
        T sum = st[0][L];
        ++L;
        for (int i = K; i >= 0; i--) {
            if ((1 << i) <= n - L && add(sum, st[i][L]) <= v) {
                sum = add(sum, st[i][L]);
                L += (1 << i);
            }
        }
        return make_pair(sum, L-1);
    }
};