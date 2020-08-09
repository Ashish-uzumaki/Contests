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
// int32_t main() {}
vector<int> convert_into_factoradic(int x){
    vector<int>v;
    int p=x;
    int i=1;
    while(p){
        v.eb(p%i);
        p=p/x;
        i++;
    }
    reverse(all(v));
    return v;
}

int factoradic_to_decimal(vector<int>& v){
    int n=v.size();
    int ans=0;
    for(int i=0,mul=n;i<n;i++,mul--) {
        ans=(ans*mul%MOD+v[i])%MOD;
    }
    return ans;
}

vector<int> find_perm(int n,vector<int>&v){
    ordered_set<int>st;
    int siz = v.size();
    vector<int>v1;
    for(int i=0;i<n-siz;i++){
        v1.pb(i);
    }
    for(int i=n-siz;i<n;i++){
        st.insert(i);
    }
    for(int i=0;i<siz;i++){
        int perm_i = *st.fbo(v[i]);//find by order
        v1.pb(perm_i);
        st.erase(perm_i);
    }
    return v1;
}

vector<int> kth_perm(int n, int k){
    vector<int> v = convert_into_factoradic(k);
    return find_perm(n,v);
}

vector<int> find_order_of_perm(vector<int>&v){
    ordered_set<int>st;
    int n = v.size();
    for(int i=0;i<n;i++){
        st.insert(v[i]);
    }
    vector<int> fac;
    for(int i=0;i<n;i++){
        int x = st.ook(v[i]);
        fac.pb(x);
        st.erase(v[i]);
    }
    return fac;
}

int order(vector<int> &v){
    vector<int> fac = find_order_of_perm(v);
    return factoradic_to_decimal(fac);
}

int32_t main() {
    int n;
    cin>>n;
    set<int>st;
    vector<int>p(n,1),q(n,1);
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    for(int i=0;i<n;i++){
        cin>>q[i];
    }
    vector<int> odp = find_order_of_perm(p);
    vector<int>odq = find_order_of_perm(q);
    int carry=0;
    for(int i=n-1;i>=0;i--){
        odp[i]+=odq[i]+carry;
        carry=odp[i]/(n-i);
        odp[i]%=(n-i);
    }
    vector<int>perm = find_perm(n,odp);
    for(int i:perm){
        cout<<i<<" ";
    }
    return 0;
}