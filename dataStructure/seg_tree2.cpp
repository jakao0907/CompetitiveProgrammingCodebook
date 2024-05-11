struct SegmentTree { // 1-base
#define cl (i << 1)
#define cr (i << 1 | 1)
#define NO_TAG 0
#define INF 1e9
  int n;
   vector<int> seg, tag;
   SegmentTree(int _n) {
    n = _n;
    seg.resize(n * 4);
    tag.resize(n * 4, NO_TAG);
  }
  SegmentTree(vector<int> &arr) {
    n = arr.size();
    seg.resize(n * 4);
    tag.resize(n * 4, NO_TAG);
    build(1, 0, n - 1, arr);
  }
  void push(int i, int l, int r) {
    if (tag[i] != NO_TAG) {
      seg[i] += tag[i]; // update by tag
      if (l != r) {
        tag[cl] += tag[i]; // push
        tag[cr] += tag[i]; // push
      }
      tag[i] = 0;
    }
  }
  void pull(int i, int l, int r) {
    int mid = (l + r) >> 1;
    push(cl, l, mid);
    push(cr, mid + 1, r);
    seg[i] = max(seg[cl], seg[cr]); // pull
  }
  void build(int i, int l, int r, vector<int> &arr) {
    if (l == r) {
      seg[i] = arr[l]; // set value
      return;
    }
    int mid = (l + r) >> 1;
    build(cl, l, mid, arr);
    build(cr, mid + 1, r, arr);
    pull(i, l, r);
  }
  void update(int i, int l, int r, int ql, int qr, int v) {
    push(i, l, r);
    if (ql <= l && r <= qr) {
      tag[i] += v;
      return;
    }
    int mid = (l + r) >> 1;
    if (ql <= mid)
      update(cl, l, mid, ql, qr, v);
    if (qr > mid)
      update(cr, mid + 1, r, ql, qr, v);
    pull(i, l, r);
  }
  int query(int i, int l, int r, int ql, int qr) {
    push(i, l, r);
    if (ql <= l && r <= qr) {
      return seg[i];
    }
    int mid = (l + r) >> 1, ans = -INF;
    if (ql <= mid)
      ans = max(ans, query(cl, l, mid, ql, qr));
    if (qr > mid)
      ans = max(ans, query(cr, mid + 1, r, ql, qr));
    return ans;
  }
  void update(int ql, int qr, int v) {
    update(1, 0, n - 1, ql, qr, v);
  }
  int query(int ql, int qr) {
    return query(1, 0, n - 1, ql, qr);
  }
};