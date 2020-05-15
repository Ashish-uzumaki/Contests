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
bool check(string &s,int i){
    if(s[i] == 'S' or s[i] == 'N' or s[i]=='S' or s[i] == 'E'){
        return true;
    }
    return false;
}
int32_t main() {
    _
    int t;
    cin >> t;
    for(int te = 1; te <= t; te++){
        string s;
        cin >> s;
        vector<vector<int>>vec;
        int n = s.size();
        vector<int>st,v2;
        v2.pb(1);
        map<char,int>mt,m;
        m['N'] = 1;
        m['S'] = 2;
        m['E'] = 3;
        m['W'] = 4;
        vector<int>v(5,0);
        vec.pb(v);
        for(int i = 0 ; i < n ;i++){
            if(s[i] == '('){
                st.pb(i);
                vector<int>v1(5,0);
                vec.pb(v1);
                if(i == 0){
                    v2.pb(1);
                }else if(s[i-1] - '0' >= 1 and s[i-1] - '0' <= 9){
                    v2.pb(s[i-1] - '0');
                }
                else{
                    v2.pb(1);
                }
            }else if(m[s[i]]){
                    vec[vec.size()-1][m[s[i]]]++;
            }else if(s[i] == ')'){
                    st.pop_back();
                    vector<int>temp = vec.back();
                    vec.pop_back();
                    tr(vec);
                    vector<int>v(5,0);
                    for(int i = 1; i<= 4;i++){
                        v[i] = v2.back() * temp[i];
                    }
                    vec.pb(v);
                    vector<int>temp1 = vec.back();
                    for(int i =1 ;i<=4;i++){
                        temp1[i]+=v[i];
                    }
                    tr(i,vec);
                    vec.pop_back();
                    vec.pop_back();
                    tr(i,vec);
                    vec.pb(temp1);
                    v2.pop_back();
                }
            }
            // tr(vec);
            cout<< "Case #" << te << ": " << endl;
        }
}