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
char to_lowercase(char c){
	if (c >= 'A' && c <= 'Z')
		return c + 32;

	return c;
}
vector<vector<int>>g;
set<char>st;
vector<int> topological_sort(int n) {
  queue<int> q;
  vector<int> indeg(n, 0);
  for (int i = 0; i < n; i++) {
    for (auto p : g[i]) {
      indeg[p]++;
    }
  }
  for (int i = 0; i < n; i++) {
    if (indeg[i] == 0 and st.find(i + 'a') != st.end()) {
      q.push(i);
    //   tr(i);
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
  // check indegrees for cycle detection even if one ofo the inedgree has more
  // than equal to 1 the cycle is present in the graph
  return T;
}
void conv(string &str) { 
    int ln = str.length();  
    for (int i=0; i<ln; i++) 
    { 
        if (str[i]>='a' && str[i]<='z') 
            str[i] = str[i] - 32; 
        else if(str[i]>='A' && str[i]<='Z') 
            str[i] = str[i] + 32; 
    } 
} 
int32_t main() {
    int te;
    cin >> te;
    for(int t = 1 ; t <= te; t++){
        int n, m;
        cin >> n >> m;
        vector<string>v;
        st.clear();
        for(int i = 0 ; i < n ; i++){
            string s;
            cin >> s;
            for (char &c: s) {
		        c = to_lowercase(c);
                st.insert(c);
	        }
            v.pb(s);
        }
        g.clear();
        g.resize(26);
        for(int i = 0; i < n - 1; i++){
            for(int j = 0; j < m ; j++){
                if(v[i+1][j] != v[i][j]){
                    g[v[i+1][j] - 'a'].pb(v[i][j] - 'a');
                }
            }
        }
        vector<int>ans = topological_sort(26);
        int cnt = -1;
        if(ans.size() != st.size()){
            cout <<"Case #"<<t<<": " <<cnt << endl;
        }else{
            string p ="";
            for(int i: ans){
                char x = i + 'a';
                p+=x;
            }
            // transform(p.begin(), all(p), ::toupper);
            conv(p);
            cout <<"Case #"<<t<<": " << p << endl;
        }
    }
}