// g++ -std=c++14

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
#define _                                                                      \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);
#define __                                                                     \
  freopen("input.txt", "r", stdin);                                            \
  freopen("output.txt", "w", stdout);
#define all(c) c.begin(), c.end()
#define inf 1000000000000000001
#define epsilon 1e-6

#define RUN_T                                                                  \
  int _t;                                                                      \
  cin >> _t;                                                                   \
  while (_t--)

#define tr(...)                                                                \
  if (DEBUG) {                                                                 \
    cout << __FUNCTION__ << ' ' << __LINE__ << " = ";                          \
    trace(#__VA_ARGS__, __VA_ARGS__);                                          \
  }

template <typename S, typename T>
ostream &operator<<(ostream &out, pair<S, T> const &p) {
  out << '(' << p.fi << ", " << p.se << ')';
  return out;
}

template <typename T> ostream &operator<<(ostream &out, set<T> const &v) {
  for (auto i = v.begin(); i != v.end(); i++)
    out << (*i) << ' ';
  return out;
}

template <typename T, typename V>
ostream &operator<<(ostream &out, map<T, V> const &v) {
  for (auto i = v.begin(); i != v.end(); i++)
    out << "\n" << (i->first) << " : " << (i->second);
  return out;
}

template <typename T, typename V>
ostream &operator<<(ostream &out, unordered_map<T, V> const &v) {
  for (auto i = v.begin(); i != v.end(); i++)
    out << "\n" << (i->first) << " : " << (i->second);
  return out;
}

template <typename T> ostream &operator<<(ostream &out, multiset<T> const &v) {
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
  cout << name << " : " << arg1 << endl;
}

template <typename T, typename... Args>
void trace(const char *names, T &&arg1, Args &&... args) {
  const char *comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1 << " | ";
  trace(comma + 1, args...);
}

int gcd(int a, int b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

#define int ll

// __builtin_popcount -> count number of bits
int val[N];
int bfs(int x,unordered_map<int,vector<pair<int,int>>>&g,unordered_map<int,vector<pair<int,int>>>&g1,vector<int>&ed){  
    queue<int>q;
    q.push(x);
    int visit[N];
    memset(visit,0,sizeof(visit));
    while(!q.empty()){
        int p=q.front();
        visit[p]=1;
        q.pop();
        for(auto t:g[p]){
            if(visit[t.fi]!=1){
                q.push(t.fi);
                g1[p].pb(mp(t.fi,ed.back()));
                g1[t.fi].pb(mp(p,ed.back()));
                val[p]=max(val[p],ed.back());
                val[t.fi]=max(val[t.fi],ed.back());
                ed.pop_back();
            }
        }
    }
}
int32_t main() {
    _
    RUN_T{
        int n,u,v,w,x;
        unordered_map<int,vector<pair<int,int>>>g;
        cin>>n;
        vector<int>ed,ver;
        memset(val,0,sizeof(val));
        for(int i=0;i<n-1;i++){
            cin>>u>>v>>w;
            g[u].pb(mp(v,w));
            g[v].pb(mp(u,w));
            ed.pb(w);
        }
        for(int i=0;i<n;i++){
            cin>>x;
            ver.pb(x);
        }
        sort(ed.begin(),ed.end());
        unordered_map<int,vector<pair<int,int>>>g1;
        bfs(1,g,g1,ed);
        vector<int>mt;
        for(int i=1;i<=n;i++){
            mt.pb(val[i]);
        }
        sort(mt.begin(),mt.end());
        sort(ver.begin(),ver.end());
        int i=0,j=0;
        while(i<n and j<n){
            if(mt[i]<ver[j]){
                i++;
                j++;
            }else{
                j++;
            }
        }
        cout<<(n-i)<<endl;
    }
}
