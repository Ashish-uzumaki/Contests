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
double dist(pair<int,int>& a, pair<int,int>& b){
    double ans = pow(a.fi - b.fi , 2) + pow(a.se - b.se , 2);
    ans = sqrt(ans);
    return ans;
}
int32_t main() {
    int n, m;
    cin  >> n >> m;
    vector<pair<int,int>>v;
    map<pair<int,int>,int>mt;
    //corner n,m
    int x,y, cnt;
    x = n, cnt = 5;
    while(x and cnt){
        mt[mp(x, m)] = 1;
        x--;
        cnt--;
    }
     y = m, cnt = 5;
    while(y and cnt){
        mt[mp(n, y)] = 1;
        y--;
        cnt--;
    }
    //corner n, 0
    x = n, cnt = 5;
    while(x and cnt){
        mt[mp(x, 0)] = 1;
        x--;
        cnt--;
    }
    y = 0, cnt = 5;
    while(y <= m and cnt){
        mt[mp(n, y)] = 1;
        y++;
        cnt--;
    }
    //corner 0,0
    x = 0, cnt = 5;
    while(x <= n and cnt){
        mt[mp(x, 0)] = 1;
        x++;
        cnt--;
    }
    y = 0, cnt = 5;
    while(y <= m and cnt){
        mt[mp(0, y)] = 1;
        y++;
        cnt--;
    }
    //corner 0, m
    x = 0, cnt = 5;
    while(x <= n and cnt){
        mt[mp(x, 0)] = 1;
        x++;
        cnt--;
    }
    y = m, cnt = 5;
    while(y and cnt){
        mt[mp(0, y)] = 1;
        y--;
        cnt--;
    }
    for(auto p: mt){
        if(p.se == 1){
            v.pb(p.fi);
        }
    }

    int len = v.size();
    // tr(v);
    pair<int,int>a, b, c , d;
    // tr(v);
    double maxi = -1.0;
    for(int i = 0; i < len; i++){
        for(int j = 0; j < len; j++){
            if(j == i) continue;
            for(int k = 0; k < len; k++){
                if(k == i or k == j) continue;
                for(int p = 0; p < len; p++){
                        if(p == i or p == j or p == k) continue;
                        double x = dist(v[i], v[j]);
                        double y = dist(v[j], v[k]);
                        double z = dist(v[k] , v[p]);
                        double val = x + y + z;
                        if( val >= maxi){
                            a = v[i];
                            b = v[j];
                            c = v[k];
                            d = v[p];
                            maxi = val;
                        }
                }
            }
        }
    }
    // tr(maxi);
    cout<< a.fi << " "<<a.se <<endl;
    cout<< b.fi << " "<<b.se <<endl;
    cout<< c.fi << " "<<c.se <<endl;
    cout<< d.fi << " "<<d.se <<endl;
}