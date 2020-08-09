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
int32_t main() {
    int n,x;
    cin>>n;
    int ans =0;
    vector<pair<int,int>>v;
    int cnt =n;
    for(int t=0;t<n;t++){
        int l;
        cin>>l;
        int maxxi=-1;
        int minni=1e8;
        vector<int>v1;
        for(int j=0;j<l;j++){
            cin>>x;
            v1.pb(x);
            if(maxxi<x){
                maxxi=x;
            }
            if(minni>x){
                minni=x;
            }
        }
        int a[l+1],b[l+1];
        a[1]=v1[0];
        for(int i=2;i<=l;i++){
            a[i]=min(a[i-1],v1[i-1]);
        }
        b[l]=v1[l-1];
        for(int i=l-1;i>=1;i--){
            b[i]=max(b[i+1],v1[i-1]);
        }
        int flag=1;
        for(int i=1;i<=l-1;i++){
            if(a[i]<b[i+1]){
                flag=0;
                // tr("yo",t);
            }
        }
        if(flag){
            v.pb(mp(minni,maxxi));
        }else{
            ans+=(cnt*2-1);
            cnt--;
        }
    }
    // tr(v);
    sort(all(v));
    vector<int>st1,st2;
    for(auto p:v){
        st1.pb(p.se);
        st2.pb(p.fi);
    }
    sort(all(st1));
    sort(all(st2));
    // int ans =0;
    // tr(st1);
    // tr(st2);
    for(int i=0;i<v.size();i++){
        int p=upper_bound(all(st1),v[i].fi)-st1.begin();
        x=p;
        // tr(v[i].fi,x,v.size()-x);
        ans+=(v.size()-x);
    }
    cout<<ans<<endl;
    // for(int i=0;i<v.size();i++){
    //     auto p=st1.lower_bound(v[i].se);
    //     int x=*p;
    //     ans+=(n-x);
    // }
}