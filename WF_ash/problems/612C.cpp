#include <bits/stdc++.h>
typedef long long ll;
typedef long double lld;
typedef long long int lli;
using namespace std;
const int N = 1000001;
const bool DEBUG = 1;
#define sd(x) scanf("%d", &x)
#define sd2(x, y) scanf("%d%d", &x, &y)
#define sd3(x, y, z) scanf("%d%d%d", &x, &y, &z)
#define endl "\n"
#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define LET(x, a) __typeof(a) x(a)
#define foreach(it, v) for (LET(it, v.begin()); it != v.end(); it++)
#define MEMS(a, b) memset(a, b, sizeof(a))
#define _			\
    ios_base::sync_with_stdio(false);			\
    cin.tie(NULL);			\
    cout.tie(NULL);
#define __ 			\
    freopen("input.txt", "r", stdin);			\
    freopen("output.txt", "w", stdout);
#define all(c) c.begin(), c.end()
#define inf 1000000000000000001
#define epsilon 1e-6
#define RUN_T			 \
    int _t; 			 \
    cin >> _t;			 \
    while (_t--)			 
#define tr(...)				\
if (DEBUG) {				\
cout << __FUNCTION__ << ' ' << __LINE__ << " = ";				\
trace(#__VA_ARGS__, __VA_ARGS__);				\
}
template <typename S, typename T>
ostream &operator<<(ostream &out, pair<S, T> const &p) {
    out << '(' << p.fi << ", " << p.se << ')';
    return out;
}
template <typename T>
ostream &operator<<(ostream &out, set<T> const &v) {
    for (auto i = v.begin(); i != v.end(); i++)
        out << (*i) << ' ';
    return out;
}
template <typename T, typename V>
ostream &operator<<(ostream &out, map<T, V> const &v) {
    for (auto i = v.begin(); i != v.end(); i++)
        out << "\n" << (i->first) <<  ":"  << (i->second);
    return out;
}
template <typename T, typename V>
ostream &operator<<(ostream &out, unordered_map<T, V> const &v) {
    for (auto i = v.begin(); i != v.end(); i++)
        out << "\n" << (i->first) <<  ":"  << (i->second);
    return out;
}
template <typename T>
ostream &operator<<(ostream &out, multiset<T> const &v) {
    for (auto i = v.begin(); i != v.end(); i++)
        out << (*i) << ' ';
    return out;
}
template <typename T>
ostream &operator<<(ostream &out, unordered_set<T> const &v) {
    for (auto i = v.begin(); i != v.end(); i++)
        out << (*i) << ' ';
    return out;
}
template <typename T>
ostream &operator<<(ostream &out, unordered_multiset<T> const &v) {
    for (auto i = v.begin(); i != v.end(); i++)
        out << (*i) << ' ';
    return out;
}
template <typename T> ostream &operator<<(ostream &out, vector<T> const &v) {
    ll l = v.size();
    for (ll i = 0; i < l - 1; i++)
        out << v[i] << ' ';
    if (l > 0)
        out << v[l - 1];
    return out;
}
template <typename T> void trace(const char *name, T &&arg1) {
    cout << name <<  ":"  << arg1 << endl;
}
template <typename T, typename... Args>
void trace(const char *names, T &&arg1, Args &&... args) {
    const char *comma = strchr(names + 1, ',');
    cout.write(names, comma - names) <<  ":"  << arg1 <<  "|" ;
    trace(comma + 1, args...);
}
int gcd(int a, int b) {
     if (b == 0)
        return a;
    return gcd(b, a % b);
}
#define int ll
bool cmp(const pair<int,int>& a,const pair<int,int>& b){
    if(a.se-a.fi<b.se-b.fi){
        return true;
    }
    return false;
}
int32_t main() {
    int n;
    cin>>n;
    vector<int>v;
    vector<pair<int,int>>v2,v1;
    set<int>st,st1;
    int a[n+1];
    // memset(a,0,siz)
    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        if(x!=0){
            v1.pb(mp(x,i));
            st1.insert(i);
            st.insert(x);
        }
        v.pb(x);
        a[i]=x;
    }
    if(st.size()==0){
        cout<<1<<endl;
        return 0;
    }
    auto t=st1.begin();
    int idx=*t;
    if(idx!=0 ){
        if(v[idx]%2==1){
            v1.pb(mp(1,0));
        }else{
            v1.pb(mp(2,0));
        }
    }
    auto t1=st1.end();
    int idx1=*t1;
    tr(idx1);
    if(idx1!=n-1 ){
        if(v[idx]%2==1){
            v1.pb(mp(1,n-1));
        }else{
            v1.pb(mp(2,n-1));
        }
    }
    vector<int>eve,odd;
    for(int i=1;i<=n;i++){
        if(st.find(i)==st.end()){
            if(i%2==0){
                eve.pb(i);
            }else{
                odd.pb(i);
            }
        }
    }
    // int x=1,y=2,z=3;
    tr(v1);
    map<pair<int,int>,int>m;
    for(int i=0;i<n-1;i++){
        v2.pb(mp(v1[i].se,v1[i+1].se));
        if(v1[i].fi%2==0 and v1[i+1].fi%2==0){
            m[mp(v1[i].se,v1[i+1].se)]=1;
        }else if(v1[i].fi%2==1 and v1[i+1].fi%2==1){
            m[mp(v1[i].se,v1[i+1].se)]=2;
        }else if(v1[i].fi%2==1 and v1[i+1].fi%2==0){
            m[mp(v1[i].se,v1[i+1].se)]=3;
        }else if(v1[i].fi%2==0 and v1[i+1].fi%2==1){
            m[mp(v1[i].se,v1[i+1].se)]=4;
        }
    }
    sort(all(v2),cmp);
    tr(v2);
    for(auto p:v2){
        if(m[p]==1){
            for(int i=p.fi+1;i<p.se;i++){
                if(!eve.empty()){
                    a[i]=eve.back();
                    eve.pop_back();
                }else{
                    a[i]=odd.back();
                }
            }
        }else if(m[p]==2){
            for(int i=p.fi+1;i<p.se;i++){
                if(!odd.empty()){
                    a[i]=odd.back();
                    odd.pop_back();
                }else{
                    a[i]=eve.back();
                }
            }
        }else if(m[p]==3){
            for(int i=p.fi+1;i<p.se;i++){
                if(!odd.empty()){
                    a[i]=odd.back();
                    odd.pop_back();
                }else{
                    a[i]=eve.back();
                }
            }
        }else if(m[p]==4){
            for(int i=p.fi+1;i<p.se;i++){
                if(!eve.empty()){
                    a[i]=eve.back();
                    eve.pop_back();
                }else{
                    a[i]=odd.back();
                }
            }
        }  
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }

}