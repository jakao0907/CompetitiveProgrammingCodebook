int ptInPoly(vector<Pt> ps,Pt p){
  int c=0;
  for(int i=0;i<ps.size();++i){
    int a=i,b=(i+1)%ps.size(); Line l(ps[a],ps[b]);
    Pt q=l.s+l.v*((l.v*(p-l.s))/norm2(l.v)); // project
    if(norm(p-q)<eps&&onseg(q,l)) return 1; // boundary
    if(dcmp(ps[a].y-ps[b].y)==0&&dcmp(ps[a].y-p.y)==0)
      continue;
    if(ps[a].y>ps[b].y) swap(a,b);
    if(ps[a].y<=p.y&&p.y<ps[b].y&&p.x<=ps[a].x+(ps[b].x-ps[a].x)/(ps[b].y-ps[a].y)*(p.y-ps[a].y)) ++c;
  }
  return (c&1)*2; // 0: outside, 1: boundary, 2: inside
} // check whether a point is in a polygon