int dp[MAXN][MAXN], a[MAXN];
int dfs(int pos, bool leadZero, bool bound, int sum, int digit) {
    if (!pos) return sum;
    if (!leadZero && !bound && dp[pos][sum] != -1) return dp[pos][sum];
    int top = bound ? a[pos] : 9, ans = 0;
    for (int i = 0; i <= top; ++i)
        ans += dfs(pos - 1, !(i || !leadZero), bound && i == a[pos], sum + ((i == digit) && (i || !leadZero)), digit);
    if (!leadZero && !bound) dp[pos][sum] = ans;
    return ans;
}
int pre(int r, int digit) { //return num of digit in [1, r]
    int cnt = 0;
    memset(dp, -1, sizeof dp);
    while (r != 0)
        a[++cnt] = r % 10, r /= 10;
    return dfs(cnt, 1, 1, 0, digit);
}