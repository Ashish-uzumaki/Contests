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
vector<set<int>>g;
vector<int>v1;
vector<int>vis1;
void dfs(int x){
    if(vis1[x] == 1) return;
    v1.pb(x);
    vis1[x] = 1;
    for(auto u: g[x]){
        if(!vis1[u]){
            dfs(u);
        }
    }
}
int32_t main() {
    int n, m, x, y;
    cin >> n >> m;
    g.resize(n);
    vis1.resize(n, 0);
    for(int i = 0 ;i < m; i++){
        cin >> x >> y;
        --x, --y;
        g[x].insert(y);
        g[y].insert(x);
    }
    dfs(0);
    if(v1.size() != n){
        cout << -1;
        return 0;
    }
    set<int>temp1;
    for(int i = 0 ; i < n; i++){
        temp1.insert(i);
    }
    set<set<int>>st;
    vector<int>vis(n, 0);
    for(int i = 0 ; i < n ; i++){
        set<int>temp;
        if(vis[i] != 1){
            set<int>b = temp1;
            for(auto p : temp1){
                int j = p;
                if(g[i].find(j) == g[i].end()){
                    temp.insert(j);
                    b.erase(j);
                    vis[j] = 1;
                }
            }
            st.insert(temp);
            temp1 = b;
        }
    }
    if(st.size()!=3){
        cout << -1 << endl;
    }else{
        vector<set<int>>g1;
        g1.resize(n);
        vector<set<int>>v;
        for(auto p: st){
            v.pb(p);
        }
        for(int i = 0; i < 3; i++){
            set<int>p = v[i];
            for(auto k: p){
                for(int j = 0 ; j < 3; j++){
                    if( i != j){
                        for(auto r:v[j]){
                            g1[k].insert(r);
                        }
                    }
                }
            }
        }
        if(g1!= g){
            cout << -1 <<endl;
            return 0;
        }
        vector<int>ans(n, 0);
        for(int i = 0; i < v.size(); i++){
            for(auto p: v[i]){
                ans[p] = i + 1;
            }
        }
        for(int i = 0 ; i < n ;i++){
            cout << ans[i] << " ";
        }
    }
}