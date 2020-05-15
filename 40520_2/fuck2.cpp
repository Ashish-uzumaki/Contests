vc v;
char mx='0';
bool flag[mxn];
int main()
{
    fast;
    ll i,j,k,n,m;
    string s;
    cin>>m>>s;
    for(i=0;i<(ll)s.size()-m+1;i++){
        k=i;
        for(j=i;j<i+m;j++) if(s[j]<s[k]) k=j;
        flag[k]=1;
        mx=max(mx,s[k]);
        v.pb(s[k]);
        i=k;
    }
    for(i=0;s[i];i++) if(flag[i]==0&&s[i]<mx) v.pb(s[i]);
    srt(v);
    for(auto x:v) cout<<x;
    return 0;
}