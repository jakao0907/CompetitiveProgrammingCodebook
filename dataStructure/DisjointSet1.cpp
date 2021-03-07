struct DisjointSet {
  int fa[MXN], h[MXN], top;
  struct Node {
    int x, y, fa, h;
    Node(int _x = 0, int _y = 0, int _fa = 0, int _h = 0)
        : x(_x), y(_y), fa(_fa), h(_h) {}
  } stk[MXN];
 
  void init(int n) {
    top = 0;
    for (int i = 1; i <= n; i++) fa[i] = i, h[i] = 0;
  }
  int f(int x) { return x == fa[x] ? x : f(fa[x]); }
  void uni(int u, int v) {
    int x = f(u), y = f(v);
    if (h[x] > h[y]) swap(x, y);
    stk[top++] = Node(x, y, fa[x], h[y]);
    if (h[x] == h[y]) h[y]++;
    fa[x] = y;
  }
  void undo(int k=1) {
    for (int i = 0; i < k; i++) {
      Node &it = stk[--top];
      fa[it.x] = it.fa;
      h[it.y] = it.h;
    }
  }
} djs;
