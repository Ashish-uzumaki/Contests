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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int>v(n),v1;
    for(int i = 0; i < n; i++){
        v[i] = s[i] - '0';
    }
    v1 = v;
    map<int,set<pair<int,int>>>mt;
    for(int i = 0; i <= 9 ;i++){
        for(int j = 0; j < n; j++){
            mt[i].insert(mp(abs(v[j] - i),j));
        }
    }
    int mini = 1e8;
    int idx = -1;
    map<int,int>m;
    for(int i=0;i<=9;i++){
        m[i] = 1e18;
    }
    for(int i = 0; i <= 9;i++){
        int ans = 0;
        int cnt = 0 ;
        for(auto j : mt[i]){
            ans += j.fi;
            cnt++;
            if(cnt == k){
                break;
            }
        }
        if(ans <= mini){
            mini = ans;
            idx = i;
            m[idx] = mini;
        }
    }
    // tr(m);
    // tr(idx);
    set<string>ans;
    for(int r =0 ;r<= 9;r++){
        if(m[r] == mini){
            vector<int>v1 = v;
            int cnt = 0;
            int last = -1;
            int idx = r;
        for(auto p:mt[idx]){
                cnt++;
                last = p.fi;
                if(cnt == k) break;
            }
            int cnt_idx = 0;
            vector<int>v2;
            for(auto p: mt[idx]){
                if(p.fi < last){
                    v1[p.se] = idx;
                    cnt_idx++;
                }
                if(p.fi == last){
                    v2.pb(p.se);
                } 
            }
            int lef = k - cnt_idx, j= 0;
            for(j = 0 ;j < v2.size(); j++){
                if( lef > 0){
                    if(v2.size() - j > lef){
                        if(v1[v2[j]] > idx){
                            v1[v2[j]] = idx;
                            lef--;
                        }
                    }else{
                        v1[v2[j]] = idx;
                        lef--;
                    }
                }
            }
            string s1= "";
            for(int i= 0; i<v1.size();i++){
                char c = v1[i] + '0';
                s1+=c;
            }
            ans.insert(s1);
        }
    }
    cout<< mini << endl;
    cout << *ans.begin();
}