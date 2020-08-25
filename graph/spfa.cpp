bool spfa(){
	deque<int> dq;
	dis[0]=0;
	dq.push_back(0);
	inq[0]=1;
	while(!dq.empty()){
		int u=dq.front();
        dq.pop_front();
		inq[u]=0;
		for(auto i:edge[u]){
			if(dis[i.first]>i.second+dis[u]){
				dis[i.first]=i.second+dis[u];
				len[i.first]=len[u]+1;
				if(len[i.first]>n)	return 1;
				if(inq[i.first])	continue;
				if(!dq.empty()&&dis[dq.front()]>dis[i.first])
					dq.push_front(i.first);
				else
					dq.push_back(i.first);
				inq[i.first]=1;
			}
		}
	}
	return 0;
}