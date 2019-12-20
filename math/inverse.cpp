f[0]=1;	//f[x]=x!
for(ll i=1;i<MAXN;i++)
	f[i]=(f[i-1]*i)%mod;
inv[MAXN-1]=ppow(f[MAXN-1],mod-2);
ll c(ll x,ll y){	//c(x,y)
	return f[x]*inv[y]%mod*inv[x-y]%mod;
}