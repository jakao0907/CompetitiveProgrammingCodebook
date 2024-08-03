inline double segP(Pt &p,Pt &p1,Pt &p2){
  if(dcmp(p1.x-p2.x)==0) return (p.y-p1.y)/(p2.y-p1.y);
  return (p.x-p1.x)/(p2.x-p1.x);
}
ld tri(Pt o, Pt a, Pt b){ return (a-o) ^ (b-o);}
double polyUnion(vector<vector<Pt>> py){ //py[0~n-1] must be filled
  int n = py.size();
  int i,j,ii,jj,ta,tb,r,d; double z,w,s,sum=0,tc,td,area;
  vector<pair<double,int>> c;
  for(i=0;i<n;i++){
    area=py[i][py[i].size()-1]^py[i][0];
  	for(int j=0;j<py[i].size()-1;j++) area+=py[i][j]^py[i][j+1];
  	if((area/=2)<0) reverse(py[i].begin(),py[i].end());
    py[i].push_back(py[i][0]);
  }
  for(i=0;i<n;i++){
    for(ii=0;ii+1<py[i].size();ii++){
      c.clear();
      c.emplace_back(0.0,0); c.emplace_back(1.0,0);
      for(j=0;j<n;j++){
        if(i==j) continue;
        for(jj=0;jj+1<py[j].size();jj++){
          ta=dcmp(tri(py[i][ii],py[i][ii+1],py[j][jj]));
          tb=dcmp(tri(py[i][ii],py[i][ii+1],py[j][jj+1]));
          if(ta==0 && tb==0){
            if((py[j][jj+1]-py[j][jj])*(py[i][ii+1]-py[i][ii])>0&&j<i){
              c.emplace_back(segP(py[j][jj],py[i][ii],py[i][ii+1]),1);
              c.emplace_back(segP(py[j][jj+1],py[i][ii],py[i][ii+1]),-1);
            }
          }else if(ta>=0 && tb<0){
            tc=tri(py[j][jj],py[j][jj+1],py[i][ii]);
            td=tri(py[j][jj],py[j][jj+1],py[i][ii+1]);
            c.emplace_back(tc/(tc-td),1);
          }else if(ta<0 && tb>=0){
            tc=tri(py[j][jj],py[j][jj+1],py[i][ii]);
            td=tri(py[j][jj],py[j][jj+1],py[i][ii+1]);
            c.emplace_back(tc/(tc-td),-1);
      } } }
      sort(c.begin(),c.end());
      z=min(max(c[0].first,0.0),1.0); d=c[0].second; s=0;
      for(j=1;j<c.size();j++){
        w=min(max(c[j].first,0.0),1.0);
        if(!d) s+=w-z;
        d+=c[j].second; z=w;
      }
      sum+=(py[i][ii]^py[i][ii+1])*s;
  } }
  return sum/2;
}