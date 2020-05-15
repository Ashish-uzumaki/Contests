#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef long long ll;
typedef long double lld;
typedef long long int lli;
using namespace std;
const int N = 1000001;
const int MOD=1e9+7;
const bool DEBUG = 1;
#define sd(x) scanf("%d", &x)
#define sd2(x, y) scanf("%d%d", &x, &y)
#define sd3(x, y, z) scanf("%d%d%d", &x, &y, &z)
#define endl "\n"
#define fi first
#define se second
#define eb emplace_back
#define fbo find_by_order
#define ook order_of_key
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
#define int ll
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
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
int gcd(int a, int b) {
     if (b == 0)
        return a;
    return gcd(b, a % b);
}
void add_self(int& a, int b) {
     a += b;
     if(a >= MOD) {
           a -= MOD;
    }
}
int get(int p ,int val ,vector<int>&v, int rg, int r){
    int mini = 3e18;
    int gb = 0;
    int br = 0;
    if( p < v.size()){
        gb =  abs(val - v[p]) * abs(val - v[p]);
        br =  abs(v[p] - r) * abs(v[p] - r);
        mini = min(rg + gb + br, mini);
    }
    if( p - 1 >= 0){
        gb =  abs(val - v[p - 1]) * abs(val - v[p - 1]);
        br =  abs(v[p - 1] - r) * abs(r - v[p - 1]);
        mini = min(rg + gb + br, mini);
    }
    return mini;
}
int32_t main() {
    RUN_T{
        int n, m ,k;
        cin >> n >> m >> k;
        vector<int>r(n), g(m), b(k);
        for(int i = 0; i < n; i++){
            cin >> r[i];
        }
        for(int i = 0; i < m; i++){
            cin >> g[i];
        }
        for(int i = 0; i < k; i++){
            cin >> b[i];
        }
        sort(all(r));
        sort(all(g));
        sort(all(b));
        int ans = 3e18;
        int val1 = 0;
        int rg = 0, gb = 0, br = 0 ;
        for(int i = 0 ; i < n; i++){
            auto p = upper_bound(g.begin(), g.end(), r[i]) - g.begin();
            int val = 3e18;
            if( p < m ){
                int key  = g[p];
                rg =  (r[i] - key)*(r[i] - key);
                auto q = upper_bound(b.begin(), b.end(), key) - b.begin();
                val = min(val, get(q, key, b, rg, r[i])); 
            }
            if(p - 1 >= 0){
                int key  = g[p-1];
                rg =  (r[i] - key)*(r[i] - key);
                auto q = upper_bound(b.begin(), b.end(), key) - b.begin();
                val = min(val, get(q, key,  b, rg, r[i]));
            }
            ans = min(ans, val);   
        }
        cout << ans << endl;
    }
}