LL len,mod;
vector<vector<LL>> operator*(vector<vector<LL>> x,vector<vector<LL>> y){
    vector<vector<LL>> ret(len,vector<LL>(len,0));
    for(int i=0;i<len;i++){
        for(int j=0;j<len;j++){
            for(int k=0;k<len;k++){
                ret[i][j]=(ret[i][j]+x[i][k]*y[k][j])%mod;
    }   }   }
    return ret;
}
struct Martix_fast_pow{ //O(len^3 lg k)
    LL init(int _len,LL m=9223372036854775783LL){
        len=_len, mod=m;
    }   // mfp.solve(k,{0, 1}, {1, 1}) k'th fib {值,係數} // 0-base
    LL solve(LL n,vector<vector<LL>> poly){
        if(n<len)   return poly[n][0];
        vector<vector<LL>> mar(len,vector<LL>(len,0)),x(len,vector<LL>(len,0));
        for(int i=0;i<len;i++)    mar[i][i]=1;
        for(int i=0;i+1<len;i++)  x[i][i+1]=1;
        for(int i=0;i<len;i++)    x[len-1][i]=poly[i][1];
        while(n){
            if(n&1) mar=mar*x;
            n>>=1, x=x*x;
        }
        LL ans=0;
        for(int i=0;i<len;i++)   ans=(ans+mar[len-1][i]*poly[i][0]%mod)%mod;
        return ans;
    }
}mfp;