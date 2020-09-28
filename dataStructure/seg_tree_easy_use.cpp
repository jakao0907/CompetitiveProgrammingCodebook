#define cl(x) (x<<1)+1
#define cr(x) (x<<1)+2
#define INF 1e9
struct seg_tree{    //0-base
	static const int MXN=1e5+5,NO_TAG=0; // to be set
	ll a[MXN],val[MXN*4],tag[MXN*4],v;
	int n,ql,qr;
	void push(int i,int l,int r){
		if(tag[i]!=NO_TAG){
			val[i]+=tag[i]; // update by tag
			if(l!=r){
				tag[cl(i)]+=tag[i]; // push
				tag[cr(i)]+=tag[i]; // push
			}
			tag[i]=NO_TAG;
		}
	}
	void pull(int i,int l,int r){
		int mid=(l+r)>>1;
		push(cl(i),l,mid);push(cr(i),mid+1,r);
		val[i]=max(val[cl(i)],val[cr(i)]); // pull
	}
	void build(int i,int l,int r){
		if(l==r){
			val[i]=a[l]; // set value
			return;
		}
		int mid=(l+r)>>1;
		build(cl(i),l,mid);build(cr(i),mid+1,r);
		pull(i,l,r);
	}
	void update(int i,int l,int r){
		push(i,l,r);
		if(ql<=l&&r<=qr){
			tag[i]+=v; // update tag
			return;
		}
		int mid=(l+r)>>1;
		if(ql<=mid) update(cl(i),l,mid);
		if(qr>mid) update(cr(i),mid+1,r);
		pull(i,l,r);
	}
	void query(int i,int l,int r){
		push(i,l,r);
		if(ql<=l&&r<=qr){
			v=max(v,val[i]); // update answer
			return;
		}
		int mid=(l+r)>>1;
		if(ql<=mid) query(cl(i),l,mid);
		if(qr>mid) query(cr(i),mid+1,r);
	}
	int Query(int _ql,int _qr){
		v=-INF, ql=_ql, qr=_qr;
		query(0,0,n-1);
		return v;
	}
	void Update(int _v,int _ql,int _qr){
		v=_v,_ql=ql,_qr=qr;
		update(0,0,n-1);
	}
	void init(){
		memset(tag,0,sizeof(tag));
		memset(val,0,sizeof(val));
	}
}tree;
