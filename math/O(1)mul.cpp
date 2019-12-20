LL mul(LL x,LL y,LL mod){
	LL ret=x*y-(LL)((long double)x/m*y)*m;
	return ret<0?ret+mod:ret;
}