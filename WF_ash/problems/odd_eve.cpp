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
// pair<int,int> find_oddval(multiset<pair<int,int>>mt,int val){
//     auto it = mt.lower_bound(make_pair(val, -1));
//     //SMALLEST large VALUE WHICH IS IT>=VAL with smallest index;
//     if(it==mt.end()){
//         pair<int,int> t = make_pair(-1,-1);
//         return t;
//     }
//     return *it;

// }
// pair<int,int> find_evenval(multiset<pair<int,int>>mt,int val){
//     auto it = mt.lower_bound(make_pair(val, -1));
//     if(it!=mt.end()){
//         if((*it).first > val){
//             tr("yo",val,(*it).first);
//             *--it;
//             tr("bye",val,(*it).first);
//         }
//         return *it;
//     }else{
//         return make_pair(-1,-1);
//     }
//     //LARGEST SMALLEST VALUE WHICH IS IT<=VAL;

// }
int oddEvenJumps(vector<int>& A) {
    int n=A.size();
    map<int,int>mt;
    int dp[n+1][2];
    dp[n][0]=n;
    dp[n][1]=n;
    for(int i=n;i>=1;i--){
        int val=A[i-1];
        auto it=mt.lower_bound(A[i]);
        if(it!=end(m)){
            dp[i][0]=dp[it.second][1];
            if (it->first == A[i]) ++it;
        }
        if (it != begin(m)) dp[i][1] = dp[prev(it)->second][0];
        m[A[i]]=i;
    }
    for(int i=1;i<=n;i++){
        cout<<dp[i][0]<<" ";
    }
    cout<<endl;
    for(int i=1;i<=n;i++){
        cout<<dp[i][1]<<" ";
    }
    cout<<endl;        
}
int32_t main() {
    int n;
    cin>>n;
    vector<int>v;
    vector<pair<int,int>>v1;
    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        v.pb(x);
        v1.pb(mp(x,i));
    }
    multiset<pair<int,int>>mt;
    mt.insert(v1[n-1]);
    for(int i=n-1;i>=0;i--){
        auto p=find_evenval(mt,v1[i].fi);
        tr(p);
        mt.insert(v1[i]);
    }
    // int ans =oddEvenJumps(v);
}