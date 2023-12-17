struct RollingHash{
#define psz 2
    vector<ll> primes={17, 75577};
    vector<array<ll, psz>> hash, base;
    void init(const string &s){
        hash.clear(); hash.resize(s.size());
        base.clear(); base.resize(s.size());
        for(int i=0;i<psz;i++){
            hash[0][i] = s[0];
            base[0][i] = 1;
        }
        for(int i=1;i<s.size();i++){
            for(int j=0;j<psz;j++){
                hash[i][j] = (hash[i-1][j] * primes[j] % MOD + s[i]) % MOD;
                base[i][j] = base[i-1][j] * primes[j] % MOD;
            }
        }
    }
    array<ll, psz> getHash(int l,int r){
        if(l == 0) return hash[r];
        array<ll, psz> ret = hash[r];
        for(int i=0;i<psz;i++){
            ret[i] -= hash[l-1][i] * base[r-l+1][i] % MOD;
            if(ret[i]<0) ret[i]+=MOD;
        }
        return ret;
    }
}Hash;