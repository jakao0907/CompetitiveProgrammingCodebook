const int MAXN = 100010;
Pt sum[MAXN], pnt[MAXN], ans, calc;
inline bool cross(Pt a, Pt b, Pt c){
	return (c.y-a.y)*(c.x-b.x) > (c.x-a.x)*(c.y-b.y);
}//pt[0]=(0,0);pt[i]=(i,pt[i-1].y+dy[i-1]),i=1~n;dx>=l
double find_max_tan(int n,int l,LL dy[]){
	int np, st, ed, now;
	sum[0].x = sum[0].y = np = st = ed = 0;
	for (int i = 1, v; i <= n; i++)
		sum[i].x=i,sum[i].y=sum[i-1].y+dy[i-1];
	ans.x = now = 1,ans.y = -1;
	for (int i = 0; i <= n - l; i++){
		while(np>1&&cross(pnt[np-2],pnt[np-1],sum[i]))
			np--;
		if (np < now && np != 0) now = np;
		pnt[np++] = sum[i];
		while(now<np&&!cross(pnt[now-1],pnt[now],sum[i+l]))
			now++;
		calc = sum[i + l] - pnt[now - 1];
		if (ans.y * calc.x < ans.x * calc.y)
			ans = calc,st = pnt[now - 1].x,ed = i + l;
	}
	return (double)(sum[ed].y-sum[st].y)/(sum[ed].x-sum[st].x);
}