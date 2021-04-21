struct seg_tree{
	ll a[MXN],val[MXN*4],tag[MXN*4],v,NO_TAG=0;
	void push(int i,int l,int r){
		if(tag[i]!=NO_TAG){
			val[i]+=tag[i]; // update by tag
			if(l!=r){
				tag[cl(i)]+=tag[i]; // push
				tag[cr(i)]+=tag[i]; // push
			}
			tag[i]=NO_TAG;
	}	}
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
	void update(int i,int l,int r,int ql,int qr){
		push(i,l,r);
		if(ql<=l&&r<=qr){
			tag[i]+=v; // update tag
			return;
		}
		int mid=(l+r)>>1;
		if(ql<=mid) update(cl(i),l,mid,ql,qr);
		if(qr>mid) update(cr(i),mid+1,r,ql,qr);
		pull(i,l,r);
	}
	int query(int i,int l,int r,int ql,int qr){
		push(i,l,r);
		if(ql<=l&&r<=qr)
			return val[i]; // update answer
		int mid=(l+r)>>1,ret=0;
		if(ql<=mid) ret=max(ret,query(cl(i),l,mid,ql,qr));
		if(qr>mid) ret=max(ret,query(cr(i),mid+1,r,ql,qr));
		return ret;
}	}tree;
