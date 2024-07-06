pair<ll, ll> heapSubtreeCount(ll x) {
    if (x == 1) return {0, 0}; 
    ll h = __lg(x);
    ll fill = (1LL << (h + 1)) - 1;
    ll l = (1LL << h) - 1 - max(0LL, fill - x - (1LL << (h - 1)));
    ll r = x - 1 - l;
    return {l, r};
};