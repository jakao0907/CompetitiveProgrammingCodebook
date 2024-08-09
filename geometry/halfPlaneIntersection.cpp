int PtSide(Pt p, Line L) {
    return dcmp((L.e - L.s)^(p - L.s));
}
bool argcmp(const Pt &a, const Pt &b) { // arg(a) < arg(b)
    int f = (Pt{a.y, -a.x} > Pt{} ? 1 : -1) * (a != Pt{});
    int g = (Pt{b.y, -b.x} > Pt{} ? 1 : -1) * (b != Pt{});
    return f == g ? (a ^ b) > 0 : f < g;
}
vector<Line> HPI(vector<Line> P) {
    sort(P.begin(), P.end(), [&](Line l, Line m) {
        if (argcmp(l.v, m.v)) return true;
        if (argcmp(m.v, l.v)) return false;
        return PtSide(l.s, m) > 0;
    });
    int n = P.size(), l = 0, r = -1;
    for (int i = 0; i < n; i++) {
        if (i and !argcmp(P[i - 1].v, P[i].v)) continue;
        while (l < r and PtSide(LLIntersect(P[r-1], P[r]), P[i]) <= 0) r--;
        while (l < r and PtSide(LLIntersect(P[l], P[l+1]), P[i]) <= 0) l++;
        P[++r] = P[i];
    }
    while (l < r and PtSide(LLIntersect(P[r-1], P[r]), P[l]) <= 0) r--;
    while (l < r and PtSide(LLIntersect(P[l], P[l+1]), P[r]) <= 0) l++;
    if (r - l <= 1 or !argcmp(P[l].v, P[r].v))
        return {}; // empty
    if (PtSide(LLIntersect(P[l], P[r]), P[l+1]) <= 0) {
        assert(0);
        return {}; // infinity
    }
    return vector(P.begin() + l, P.begin() + r + 1);
}