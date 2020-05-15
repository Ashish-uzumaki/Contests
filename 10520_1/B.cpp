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
int32_t main() {
    _
    int n , m , k;
    cin >> n >> m >>k;
    vector<vector<int>>v(m),arr,dep;
    int maxi = 0, mini = 1e6;
    for(int i = 0 ; i < m; i++){
        vector<int>temp(4);
        cin >> temp[0] >> temp[1] >> temp[2] >> temp[3];
        if( temp[2] == 0){
            arr.pb(temp);
        }else{
            dep.pb(temp);
        }
    }
    sort(all(arr));
    sort(all(dep));
    if(arr.size() == 0 or dep.size() == 0){
        cout << -1 ;
        return 0;
    }
    maxi = arr[arr.size() - 1][0];
    mini = dep[0][0];
    vector<int>mt(n + 1, 1e12);
    set<int>st;
    vector<int>ans(maxi + 1, 1e18);
    int sum = 1e12*n;
    for(int i = 0; i < arr.size(); i++){
        vector<int>temp = arr[i];
        int val = mt[temp[1]];
        mt[temp[1]] = min(mt[temp[1]], temp[3]);
        sum -= val;
        sum += mt[temp[1]];
        st.insert(temp[1]);
        if(st.size() == n){
            ans[temp[0]] = sum;
        }
    }
    for(int i = 1; i <= maxi ;i++){
        ans[i] = min(ans[i],ans[i-1]);
    }
    st.clear();
    mt.clear();
    mt.resize(n + 1, 1e12);
    sum = n*1e12;
    vector<int>ans2;
    int maxi2 = dep[dep.size() - 1][0];
    ans2.resize(maxi2 + 1, 1e18);

    for(int i = dep.size() - 1; i >= 0; i--){
        vector<int>temp = dep[i];
        int val = mt[temp[2]];
        mt[temp[2]] = min(mt[temp[2]], temp[3]);
        sum -= val;
        sum += mt[temp[2]];
        st.insert(temp[2]);
        if(st.size() == n){
            ans2[temp[0]] = sum;
        }
    }
    for(int i = maxi2 - 1; i >=0 ;i--){
        ans2[i] = min(ans2[i],ans2[i+1]);
    }
    int fin_ans = 1e18 ;
    for(int i = 1; i <= maxi; i++){
        if(ans[i] >= 1e18){
            continue;
        }
        int key = i + k + 1;
        if( key <= maxi2){
            fin_ans = min(fin_ans, ans2[key] + ans[i]);
        }
    }
    if(fin_ans >= 1e18){
        fin_ans = -1;
    }
    cout << fin_ans << endl;
}