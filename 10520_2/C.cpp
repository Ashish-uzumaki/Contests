#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef long long ll;
typedef long double lld;
typedef long long int lli;
using namespace std;
const int N = 1011;
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
int diff(vector<string>&a ,vector<string> &b){
    int cnt = 0;
    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < a[0].size(); j++){
            if(a[i][j] != b[i][j]){
                cnt++;
            }
        }
    }
    return cnt;
}
int dist[N], parent[N];
bool vis[N];
int k;
vector<pair<int, int> > g[N], treee[N];

int primsMST(int source) //Finds the cost and makes the MST
{
	for(int i = 1;i <= k;i++)
		dist[i]=1e18;
	set<pair<int, int> > s;
	s.insert({0, source});
	int cost = 0;
	dist[source] = 0;
	while(!s.empty())
	{
		auto x = *(s.begin());
		s.erase(x);
		vis[x.second] = 1;
		cost += x.first;
		int u = x.second;
		int v = parent[x.second];
		int w = x.first;
		treee[u].push_back({v, w});
		treee[v].push_back({u, w});
		for(auto it: g[x.second])
		{
			if(vis[it.first])
				continue;
			if(dist[it.first] > it.second)
			{
				s.erase({dist[it.first], it.first});
				dist[it.first] = it.second;
				s.insert({dist[it.first], it.first});
				parent[it.first] = x.second;
			}
		}
	}
	return cost;
}
vector<pair<int,int>>ans;
set<pair<int,int>>st;
void dfs(int u, int par){
    if(par != -1){
        if(st.find(mp(u, par)) == st.end()){
            ans.pb(mp(u, par));
            st.insert(mp(u, par));
        }
    }
    for(auto v: treee[u]){
        if(v.fi != par){
            dfs(v.fi, u);
        }
    }
}
int32_t main() {
    int n , m , w;
    cin >> n >> m >> k >> w;
    vector<vector<string>>v;
    for(int i = 1 ;i <= k; i++){
        vector<string> str;
        string s;
        for(int p = 0; p < n; p++){
            cin >> s;
            str.pb(s);
        }
        for(int j = 0 ; j < v.size(); j++){
            int val = diff(v[j], str);
            g[j + 1].pb(mp(i, val * w));
            g[i].pb(mp( j + 1 ,val * w));
        }
        v.pb(str);
        g[0].pb(mp(i , n * m));
    }
    int val = primsMST(0);
    dfs(0, -1);
    cout << val << endl;
    for(auto p: ans){
        if(p.fi == 0 and p.se == 0){
            continue;
        }
        cout << p.fi <<" "<<p.se << endl;
    }
}