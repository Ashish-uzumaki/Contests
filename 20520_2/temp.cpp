const int mod=1e9+7;
const int mxn=5e6+9;
const ld eps=1e-9;
//ll qpow(ll n,ll k) {ll ans=1;while(k){if(k&1) ans=(ans*n)%mod;n=(n*n)%mod;k>>=1;}return ans;}
bool ck[mxn];
int a[100005],nxt,ni;
bool vis[mxn];
int spf[mxn];
vll v;
void sieve()
{
    int i,j,k;
    for(i=1;i<mxn;i++) spf[i]=i;
    for(i=2;i<mxn;i+=2) spf[i]=2;
    for(i=3;i*i<mxn;i+=2){
        if(spf[i]==i) for(j=i+i;j<mxn;j+=i) spf[j]=min(spf[j],i);
    }
    for(i=2;i<mxn;i++) if(spf[i]==i) v.pb(i);
}
bool yo(int n)
{
    while(n>1){
        if(vis[spf[n]]) return 0;
        n/=spf[n];
    }
    return 1;
}
void dope(ll n)
{
    while(n>1) vis[spf[n]]=1,n/=spf[n];
   for(ll j=ni;j<v.size();j++) if(vis[v[j]]==0){
        nxt=v[j];
        ni=j;
        break;
   }
    return;
}
int main()
{
    fast;
    int i,j,k,n,m,pre,flag=0;
    sieve();
    cin>>n;
    for(i=0;i<n;i++) cin>>a[i];
    cout<<a[0]<<' ';
    pre=a[0];
    dope(pre);
    for(i=1;i<n;i++){
        if(flag==1){
            j=min(2,a[i]);
            if(j<nxt) j=nxt;
        }
        else j=a[i];
        for(;j<mxn;j++){
            if(yo(j)){
                if(j>a[i]) flag=1;
                dope(j);
                cout<<j<<' ';
                pre=j;
                break;
            }
        }
    }
    return 0;
}