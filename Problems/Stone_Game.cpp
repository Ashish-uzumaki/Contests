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
int flag = false;
int dp[500][500][2];
int recur(int l , int r, vector<int>&p, int t, int ans1, int ans2){
    if(l == r){
        if( t == 0){
            ans2 += p[l];
        }else{
            ans1 += p[l];
        }
        return ans1;
    }
    if(dp[l][r][t] != -1) return dp[l][r][t];
    if(t){
        int val = max(recur(l + 1, r, p, t^1, ans1 + p[l], ans2) ,recur(l, r - 1, p, t^1, ans1 + p[r], ans2));
        dp[l][r][t] = val;
        return val;
    }else{
        int val  = min(recur(l + 1, r, p, t^1, ans1,ans2 + p[l]) ,recur(l, r - 1, p, t^1, ans1, ans2 + p[r]));
        dp[l][r][t] = val;
        return val;
    }
    
}
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                dp[i][j][0] = -1;
                dp[i][j][1] = -1;
            }
        }
        int sum = 0;
        for(int i = 0; i < n; i++){
            dp[i][i][0] = piles[i];
            dp[i][i][1] = piles[i];
            sum += piles[i];
        }
        int t = 1;
        int ans1 = 0, ans2 = 0;
        int p = recur(0, n-1, piles, t, ans1, ans2);
        cout << p << endl;
        if(p >= sum - p){
            return true;
        }else{
            return false;
        }
    }
int32_t main() {
    _
    int n;
    cin >> n;
    vector<int>v;
    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        v.pb(x);
    }
    cout<<stoneGame(v)<<endl;
}