LL mul(LL x,LL y,LL mod){
	LL ret=x*y-(LL)((long double)x/mod*y)*mod;
	return ret<0?ret+mod:ret;
}
