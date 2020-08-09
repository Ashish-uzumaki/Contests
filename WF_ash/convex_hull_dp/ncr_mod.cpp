const int MOD=1e9+7;
int f[200005];
int r[200005];
int power(int x){
    int y=MOD-2;
    int ret=1;
    while(y)
    {
        if(y%2)
            ret=(ret*x)%MOD;
        x=(x*x)%MOD;
        y>>=1;
    }
    return ret;
}
int ncr(int n,int m){
    if(n<m)return 0;
    int t1=power(f[n-m]);
    int t2=power(f[m]);
    t1=(t1*t2)%MOD;
    return (f[n]*t1)%MOD;
}
// return (fac[n]* modInverse(fac[r], p) % p * 
//         modInverse(fac[n-r], p) % p) % p;