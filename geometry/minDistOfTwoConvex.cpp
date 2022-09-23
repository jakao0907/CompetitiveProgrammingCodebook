double TwoConvexHullMinDis(Pt P[],Pt Q[],int n,int m){
  int mn=0,mx=0; double tmp,ans=1e9;
  for(int i=0;i<n;++i) if(P[i].y<P[mn].y) mn=i;
  for(int i=0;i<m;++i) if(Q[i].y>Q[mx].y) mx=i;
  P[n]=P[0]; Q[m]=Q[0];
  for (int i=0;i<n;++i) {
    while(tmp=((Q[mx+1]-P[mn+1])^(P[mn]-P[mn+1]))>((Q[mx]-P[mn+1])^(P[mn]-P[mn+1]))) mx=(mx+1)%m;
    if(tmp<0) // pt to segment distance
      ans=min(ans,dis(Line(P[mn],P[mn+1]),Q[mx]));
    else // segment to segment distance
      ans=min(ans,dis(Line(P[mn],P[mn+1]),Line(Q[mx],Q[mx+1])));
    mn=(mn+1)%n;
  }
  return ans;
}