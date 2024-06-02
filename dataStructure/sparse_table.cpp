struct SparseTable{
#define MAXN 500005
#define K 20
    int n;
    long long st[K + 1][MAXN];
    SparseTable(vector<long long> &arr){
        n = arr.size();
        copy(arr.begin(), arr.end(), st[0]);
        for (int i = 1; i <= K; i++)
        for (int j = 0; j + (1 << i) <= n; j++)
            st[i][j] = (st[i - 1][j] & st[i - 1][j + (1 << (i - 1))]);
    }
    long long query(int L, int R){
        long long ret = 0;
        for (int i = K; i >= 0; i--) {
            if ((1 << i) <= R - L + 1) {
                ret += st[i][L];
                L += 1 << i;
            }
        }
        return ret;
    }
    pair<long long, int> less_equal(int L, int v){//sum, index
        long long sum = st[L][0];
        ++L;
        for (int i = K; i >= 0; i--) {
            if ((1 << i) <= n - L && (sum+st[i][L]) <= v) {
                sum += st[i][L];
                L += (1 << i);
            }
        }
        return make_pair(sum, L-1);
    }
};