#define MXN 200005
struct SPFA{
  int n;
  LL inq[MXN], len[MXN];
  vector<LL> dis;
  vector<pair<int, LL>> edge[MXN];
  void init(int _n){
    n = _n;
    dis.clear(); dis.resize(n, 1e18);
    for(int i = 0; i < n; i++){
      edge[i].clear();
      inq[i] = len[i] = 0;
  } }
  void addEdge(int u, int v, LL w){
    edge[u].push_back({v, w});
  }
  vector<LL> solve(int st = 0){ 
    deque<int> dq; //return {-1} if has negative cycle
    dq.push_back(st); //otherwise return dis from st
    inq[st] = 1; dis[st] = 0;
    while(!dq.empty()){
      int u = dq.front();  dq.pop_front();
      inq[u] = 0;
      for(auto [to, d] : edge[u]){
        if(dis[to] > d+dis[u]){
          dis[to] = d+dis[u];
          len[to] = len[u]+1;
          if(len[to] > n)	return {-1};
          if(inq[to])	continue;
          (!dq.empty()&&dis[dq.front()] > dis[to]?
              dq.push_front(to) : dq.push_back(to));
          inq[to] = 1;
    }	}	}
    return dis;
} }spfa;