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
int add(int x, int a, int h){
    if(x + a > h){
        a = (a - ( h - x));
        return a;
    }else{
        return x + a;
    }
}
int sub(int x, int val, int h){
    if( x - val == 0){
        return h;
    }else{
        return x - 1;
    }
}
int32_t main() {
    int n, l, r, h;
    cin >> n >> h >> l >> r;
    vector<int>v(n+1);
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }
    vector<vector<int>>dp(n+1, vector<int>(h+1,0));
    dp[1][v[1]] = 1;
    dp[1][v[1]-1] = 1;
    tr(add(15, 17, 24));
    for(int i = 2; i <= n ; i++){
        for(int j = 1; j <= h; j++){
            if(dp[i-1][j] == 1){
                int val1 = add(j, v[i], h);
                int val2 = add(j, v[i] - 1, h);
                dp[i][val1] = 1;
                dp[i][val2] = 1;
            }
        }
    }
    vector<vector<int>>dp2(n + 1, vector<int>(h + 1, 0));
    for(int j = 1; j <= h; j++){
        if(dp[1][j] == 1){
            if( j >= l and j <= r){
                dp2[1][j] = 1;
            }
        }
    }
    for(int i = 2; i <= n ; i++){
        for(int j = 1; j <= h; j++){
            if(dp[i-1][j] == 1){
                int val1 = add(j, v[i], h);
                int val2 = add(j, v[i] - 1, h);
                if(val1 >= l and val1 <= r){
                    dp2[i][val1] = max(dp2[i - 1][j] + 1 , dp2[i][val1]);
                }else{
                    dp2[i][val1] = max(dp2[i - 1][j] , dp2[i][val1]);
                }
                if(val2 >= l and val2 <= r){
                    dp2[i][val2] = max(dp2[i - 1][j] + 1 , dp2[i][val2]);
                }else{
                    dp2[i][val2] = max(dp2[i - 1][j], dp2[i][val2]);
                }
            }
        }
    }
    int maxi = -1;
    for(int i = 1; i <= h; i++){
        maxi = max( dp2[n][i], maxi);
    }
    cout << maxi <<endl;
}