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
        }
    }
    void addEdge(int u, int v, LL w){
        edge[u].push_back({v, w});
    }
    vector<LL> solve(int st = 0){ // return {-1} is contain negative cycle
        deque<int> dq;            // otherwise return distance from st
        dis[st] = 0;
        dq.push_back(st);
        inq[st] = 1;
        while(!dq.empty()){
            int u = dq.front();
            dq.pop_front();
            inq[u] = 0;
            for(auto i:edge[u]){
                if(dis[i.first] > i.second+dis[u]){
                    dis[i.first] = i.second+dis[u];
                    len[i.first] = len[u]+1;
                    if(len[i.first] > n)	return {-1};
                    if(inq[i.first])	continue;
                    (!dq.empty()&&dis[dq.front()] > dis[i.first] ? 
                        dq.push_front(i.first) : dq.push_back(i.first));
                    inq[i.first] = 1;
        }	}	}
        return dis;
    }
}spfa;