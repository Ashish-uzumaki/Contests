#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef long long ll;
typedef long double lld;
typedef long long int lli;
using namespace std;
const int N = 1000001;
const int MOD = 1e9+7;
const bool DEBUG = 1;
#define sd(x) scanf("%d ", &x)
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
#define __			\
    freopen("input.txt", "r", stdin);			\
    freopen("output.txt", "w", stdout);
#define all(c) c.begin(), c.end()
#define inf 1000000000000000001
#define epsilon 1e-6
#define int ll
#define RUN_T			\
    int _t;			\
    cin >> _t;			\
    while (_t--)
#define tr(...)			\
if (DEBUG) {			\
    cout << __FUNCTION__ << ' ' << __LINE__ << " = ";			\
    trace(#__VA_ARGS__, __VA_ARGS__);			\
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
vector<vector<int>>g;
int flag = 0;
vector<int> topological_sort(int n) {
  queue<int> q;
  vector<int> indeg(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    for (auto p : g[i]) {
      indeg[p]++;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (indeg[i] == 0) {
      q.push(i);
    }
  }
  vector<int> T;
  int ans = 0;
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    T.push_back(x);
    for (auto y : g[x]) {
      indeg[y]--;
      if (indeg[y] == 0) {
        q.push(y);
      }
    }
  }
  for(int i = 1 ; i <= n; i++){
      if(indeg[i] > 0){
          flag = 1;
          break;
      }
  }
  // check indegrees for cycle detection even if one of the inedgree has more
  // than equal to 1 the cycle is present in the graph
  return T;
}
void printalledges(vector<vector<int>>&g,int n){
  set<pair<int,int>>st;
  vector<pair<int,int>>v;
  for(int i = 1; i <= n; i++ ){
      for(auto p: g[i]){
          auto x = mp(i, p);
          if(st.find(x) == st.end()){
            st.insert(mp(i, p));
            v.pb(mp(i, p));
          }
      }
  } 
  cout <<"YES" << endl;
  for(auto p: v){
      cout << p.fi <<" "<<p.se << endl;
  }
}
int32_t main() {
    _
    RUN_T{
        int n , m, x, y, t;
        cin >> n >> m;
        g.clear(); 
        g.resize(n + 1);
        flag = 0;
        vector<pair<int,int>>v;
        for(int i = 1; i <= m; i++){
            cin >> t >> x >> y;
            if( t == 1){
                g[x].pb(y); 
            }else{
                v.pb(mp(x, y));
            }
        }
        vector<int>idx(n + 1, -1);
        vector<int>ans = topological_sort(n);
        for(int i = 0 ;i < ans.size(); i++){
            idx[ans[i]] = i + 1;
        }
        if(flag == 1){
            cout << "NO" << endl;
        }else{
            for(auto p: v){
                int a = idx[p.fi];
                int b = idx[p.se];
                if(a > b){
                    g[p.se].pb(p.fi);
                }else{
                    g[p.fi].pb(p.se);
                }
            }
            printalledges(g, n);
        }
    }
}