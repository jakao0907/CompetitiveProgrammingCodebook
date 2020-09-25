template <int MAXN, class T = int>
struct HLPP {
  const T INF = numeric_limits<T>::max();
  struct Edge {
    int to, rev; T f;
  };
  int n, s, t;
  vector<Edge> adj[MAXN];
  deque<int> lst[MAXN];
  vector<int> gap[MAXN];
  int ptr[MAXN];
  T ef[MAXN];
  int h[MAXN], cnt[MAXN], work, hst=0/*highest*/;
  void init(int _n, int _s, int _t) {
  	n=_n+1; s = _s; t = _t;
    for(int i=0;i<n;i++) adj[i].clear();
  }
  void addEdge(int u,int v,T f,bool isDir = true){
    adj[u].push_back({v,adj[v].size(),f});
    adj[v].push_back({u,adj[u].size()-1,isDir?0:f});
  }
  void updHeight(int v, int nh) {
    work++;
    if(h[v] != n) cnt[h[v]]--;
    h[v] = nh;
    if(nh == n) return;
    cnt[nh]++, hst = nh; gap[nh].push_back(v);
    if(ef[v]>0) lst[nh].push_back(v), ptr[nh]++;
  }
  void globalRelabel() {
    work = 0;
    fill(h, h+n, n);
    fill(cnt, cnt+n, 0);
    for(int i=0; i<=hst; i++)
        lst[i].clear(), gap[i].clear(), ptr[i] = 0;
    queue<int> q({t}); h[t] = 0;
    while(!q.empty()) {
      int v = q.front(); q.pop();
      for(auto &e : adj[v])
        if(h[e.to] == n && adj[e.to][e.rev].f > 0)
          q.push(e.to), updHeight(e.to, h[v] + 1);
      hst = h[v];
  } }
  void push(int v, Edge &e) {
    if(ef[e.to] == 0)
      lst[h[e.to]].push_back(e.to), ptr[h[e.to]]++;
    T df = min(ef[v], e.f);
    e.f -= df, adj[e.to][e.rev].f += df;
    ef[v] -= df, ef[e.to] += df;
  }
  void discharge(int v) {
    int nh = n;
    for(auto &e : adj[v]) {
      if(e.f > 0) {
        if(h[v] == h[e.to] + 1) {
          push(v, e);
          if(ef[v] <= 0) return;
        }
        else nh = min(nh, h[e.to] + 1);
    } }
    if(cnt[h[v]] > 1) updHeight(v, nh);
    else {
      for(int i = h[v]; i < n; i++) {
        for(auto j : gap[i]) updHeight(j, n);
        gap[i].clear(), ptr[i] = 0;
  } } }
  T solve() {
    fill(ef, ef+n, 0);
    ef[s] = INF, ef[t] = -INF;
    globalRelabel();
    for(auto &e : adj[s]) push(s, e);
    for(; hst >= 0; hst--) {
      while(!lst[hst].empty()) {
        int v=lst[hst].back(); lst[hst].pop_back();
        discharge(v);
        if(work > 4 * n) globalRelabel();
    } }
    return ef[t] + INF;
} };
