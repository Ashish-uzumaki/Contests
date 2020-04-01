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
vector<pair<int,int>> intersect(vector<int> v1, vector<int>v2){
    int i = 1, j = 1;
    int n = v1.size(), m = v2.size();
    vector<pair<int,int>>ans;
    while(i <= n and j <= m){
        if(v1[i] == v2[j]){
            ans.pb(mp(i,j));
            i++;
            j++;
        }
        else if(v1[i] < v2[j]){
            i++;
        }else{
            j++;
        }
    }
    return ans;
}
int32_t main() {
    _
    while(1){
        int n, m;
        cin >> n;
        if( n == 0) break;
        vector<int>v(n+1, 0);
        set<int>st;
        vector<pair<int,int>>v2;
        for(int i = 1; i <= n; i++){
            cin >> v[i];
        }
        cin >> m;
        vector<int>v1(m+1, 0);
        for(int i = 1; i <= m; i++){
            cin >> v1[i];
        }
        v2 = intersect(v,v1);
        v2.pb(mp(n,m));
        int p = v2.size();
        vector<vector<int>>dp(p,vector<int>(2,0)),temp(p,vector<int>(2,0));
        for(int i = 1;i <= n ;i++){
            v[i]+=v[i-1];
        }
        for(int i = 1;i <= m ;i++){
            v1[i]+=v1[i-1];
        }
        pair<int,int> pt ={0,0};
        for(int i = 0; i < p ; i++){
            auto t = v2[i];
            temp[i][0] = v[t.fi]-v[pt.fi];
            temp[i][1] = v1[t.se]-v1[pt.se];
            dp[i][0] = temp[i][0];
            dp[i][1] = temp[i][1];
            pt = t;
        }
        for(int i = 1; i < p; i++){
            dp[i][0] += max(dp[i-1][0], dp[i-1][1]);
            dp[i][1] += max(dp[i-1][0], dp[i-1][1]);
        }
        cout<< max(dp[p-1][0], dp[p-1][1]) << endl;
    }
}