const int MXN=100005;
const int MXK=10;
struct KDTree{
  struct Nd{
    LL x[MXK],mn[MXK],mx[MXK];
    int id,f;
    Nd *l,*r;
  }tree[MXN],*root;
  int n,k;
  LL dis(LL a,LL b){return (a-b)*(a-b);}
  LL dis(LL a[MXK],LL b[MXK]){
    LL ret=0;
    for(int i=0;i<k;i++) ret+=dis(a[i],b[i]);
    return ret;
  }
  void init(vector<vector<LL>> &ip,int _n,int _k){
    n=_n,k=_k;
    for(int i=0;i<n;i++){
      tree[i].id=i;
      copy(ip[i].begin(),ip[i].end(),tree[i].x);
    }
    root=build(0,n-1,0);
  }
  Nd* build(int l,int r,int d){
    if(l>r) return NULL;
    if(d==k) d=0;
    int m=(l+r)>>1;
    nth_element(tree+l,tree+m,tree+r+1,[&](const Nd &a,const Nd &b){return a.x[d]<b.x[d];});
    tree[m].f=d;
    copy(tree[m].x,tree[m].x+k,tree[m].mn);
    copy(tree[m].x,tree[m].x+k,tree[m].mx);
    tree[m].l=build(l,m-1,d+1);
    if(tree[m].l){
      for(int i=0;i<k;i++){
        tree[m].mn[i]=min(tree[m].mn[i],tree[m].l->mn[i]);
        tree[m].mx[i]=max(tree[m].mx[i],tree[m].l->mx[i]);        
      }
    }
    tree[m].r=build(m+1,r,d+1);
    if(tree[m].r){
      for(int i=0;i<k;i++){
        tree[m].mn[i]=min(tree[m].mn[i],tree[m].r->mn[i]);
        tree[m].mx[i]=max(tree[m].mx[i],tree[m].r->mx[i]);        
      }
    }
    return tree+m;
  }
  LL pt[MXK],md;
  int mID;
  bool touch(Nd *r){
    LL d=0;
    for(int i=0;i<k;i++){
      if(pt[i]<=r->mn[i]) d+=dis(pt[i],r->mn[i]);
        else if(pt[i]>=r->mx[i]) d+=dis(pt[i],r->mx[i]);
    }
    return d<md;
  }
  void nearest(Nd *r){
    if(!r||!touch(r)) return;
    LL td=dis(r->x,pt);
    if(td<md) md=td,mID=r->id;
    nearest(pt[r->f]<r->x[r->f]?r->l:r->r);
    nearest(pt[r->f]<r->x[r->f]?r->r:r->l);
  }
  pair<LL,int> query(vector<LL> &_pt,LL _md=1LL<<57){
    mID=-1,md=_md;
    copy(_pt.begin(),_pt.end(),pt);
    nearest(root);
    return {md,mID};
  }
}tree;