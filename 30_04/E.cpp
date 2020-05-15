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
#define P pair<int,int>
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

struct edge{
    int to, cost, i;
    edge(int _to, int _cost, int _i){
        to = _to, cost = _cost, i = _i;
    }
};
 
int n,m,k,a,b,y;
vector<edge> G[N];
vector<int>dis;
int prv[N], pvi[N];
vector<int> res;
 
void dijkstra(){

    dis.resize(N, inf);
    dis[0] = 0;
    priority_queue<P, vector<P>, greater<P> > pque;
    pque.push({0, 0});
 
    while(!pque.empty()){
        P p = pque.top(); pque.pop();
        int i = p.second;
        int dist = p.first;
        if(dist > dis[i]) continue;
 
        for(edge e : G[i]){
            if(e.cost + dis[i] < dis[e.to]){
                dis[e.to] = e.cost + dis[i];
                pque.push({dis[e.to], e.to});
                prv[e.to] = i;
                pvi[e.to] = e.i;
            }
        }
    }
}
 
int cur_edges;
void dfs(int i, int par){
    if(cur_edges == 0) return ;
    for(auto e : G[i]){
        if(e.to != par && cur_edges > 0){
            res.push_back(e.i);
            cur_edges--;
            dfs(e.to, i);
        }
    }
}
 
int32_t main(){
    _
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++){
        cin >> a >> b >> y;
        a--, b--;
        G[a].push_back(edge(b, y, i));
        G[b].push_back(edge(a, y, i));
    }
    dijkstra();

    for(int i = 0; i < n; i++) G[i].clear();
    for(int i = 1; i < n; i++){
        G[prv[i]].push_back(edge(i, 1, pvi[i]));
    }
 
    cur_edges = k;
    dfs(0, -1);

    cout << res.size() << endl;
    for(int x : res) cout << x + 1 << " ";
 
}