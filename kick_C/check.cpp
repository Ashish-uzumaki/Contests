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
vector<int> recalc_pref(vector<int>A){
    int n = A.size();
    vector<int>pref(n+1, 0);
    int sig  = 1;
    for(int i = 0 ; i < n; i++){
        if(i % 2 == 0){
            sig = 1;
        }else{
            sig = -1;
        }
        pref[i+1] = sig*A[i]*(i+1) + pref[i];
    }
    return pref;
}
vector<int> recalc_pref2(vector<int>A){
    int n = A.size();
    vector<int>pref(n+1, 0);
    int sig = 1;
    for(int i = 0 ; i < n; i++){
        if(i % 2 == 0){
            sig = 1;
        }else{
            sig = -1;
        }
        pref[i+1] = sig*A[i] + pref[i];
    }
    return pref;
}
int32_t main() {
    int te;
    cin >> te;
    for(int t = 1 ; t <= te; t++){
        int n, m;
        cin  >> n >> m;
        vector<int>v(n);
        for(int i = 0; i < n; i++){
            cin>>v[i];
        }
        vector<int>pref_A,pref_B;
        pref_A = recalc_pref(v);
        pref_B = recalc_pref2(v);
        char c;
        int x, y;
        int cnt = 0;
        for(int i = 0 ;i <  m; i++){
            cin >> c >> x >> y;
            if(c == 'Q'){
                int val1 = pref_A[y] - pref_A[x - 1];
                int val2 = (x - 1) * (pref_B[y] - pref_B[x - 1]);
                val2  = val1 - val2;
                if(x % 2 == 0){
                    val2 = val2 * (-1);
                }
                tr(val2);
                cnt += val2;
            }else{
                v[x-1] = y;
                pref_A = recalc_pref(v);
                pref_B = recalc_pref2(v);
            }
        }
        cout <<"Case #"<<t<<": " <<cnt << endl;
        
    }
}