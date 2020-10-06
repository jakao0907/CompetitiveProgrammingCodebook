LL mul(LL x,LL y,LL mod){
	LL ret=x*y-(LL)((long double)x/mod*y)*mod;
	// LL ret=x*y-(LL)((long double)x*y/mod+0.5)*mod;
	return ret<0?ret+mod:ret;
}
