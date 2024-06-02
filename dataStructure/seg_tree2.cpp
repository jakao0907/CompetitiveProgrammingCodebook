template<class T>
struct SegmentTree { // 1-base
#define cl (i << 1)
#define cr (i << 1 | 1)
#define NO_TAG 0
#define INF 1e9
  int n;
  vector<T> seg, tag;
  SegmentTree(int _n) {
    n = _n;
    seg.resize(n * 4, NO_TAG);
    tag.resize(n * 4, NO_TAG);
  }
  SegmentTree(vector<T> &arr) {
    n = arr.size();
    seg.resize(n * 4);
    tag.resize(n * 4, NO_TAG);
    build(1, 0, n - 1, arr);
  }
  T add(T ori, T addValue){
    return (ori + addValue); // range add value
    // return addValue; // range set value
  }
  T combine(T lhs, T rhs){
    return (lhs + rhs); // query range sum
    // return max(lhs, rhs); // query range max
  }
  void push(int i, int l, int r) {
    if (tag[i] != NO_TAG) {
      seg[i] = add(seg[i], tag[i]);
      if (l != r) {
        tag[cl] = add(tag[cl], tag[i]);
        tag[cr] = add(tag[cr], tag[i]);
      }
      tag[i] = NO_TAG;
    }
  }
  void pull(int i, int l, int r) {
    int mid = (l + r) >> 1;
    push(cl, l, mid);
    push(cr, mid + 1, r);
    seg[i] = combine(seg[cl], seg[cr]);
  }
  void build(int i, int l, int r, vector<T> &arr) {
    if (l == r) {
      seg[i] = arr[l]; // set value
      return;
    }
    int mid = (l + r) >> 1;
    build(cl, l, mid, arr);
    build(cr, mid + 1, r, arr);
    pull(i, l, r);
  }
  void update(int i, int l, int r, int ql, int qr, T v) {
    push(i, l, r);
    if (ql <= l && r <= qr) {
      tag[i] = add(tag[i], v);
      return;
    }
    int mid = (l + r) >> 1;
    if (ql <= mid)
      update(cl, l, mid, ql, qr, v);
    if (qr > mid)
      update(cr, mid + 1, r, ql, qr, v);
    pull(i, l, r);
  }
  T query(int i, int l, int r, int ql, int qr) {
    push(i, l, r);
    if (ql <= l && r <= qr) {
      return seg[i];
    }
    int mid = (l + r) >> 1;
    T ret = NO_TAG;
    bool ok = false;
    if (ql <= mid){
      ret = query(cl, l, mid, ql, qr), ok = true;
    }
    if (qr > mid){
      if(ok)  ret = combine(ret, query(cr, mid + 1, r, ql, qr));
      else    ret = query(cr, mid + 1, r, ql, qr);
    }
    return ret;
  }
  void update(int ql, int qr, T v) {
    update(1, 0, n - 1, ql, qr, v);
  }
  T query(int ql, int qr) {
    return query(1, 0, n - 1, ql, qr);
  }
};