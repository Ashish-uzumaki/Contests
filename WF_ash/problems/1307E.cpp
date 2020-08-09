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
unordered_map< int , int> d , mt;
int32_t main() {
    _
    int n , m;
    cin >> n >> m;
    vector<int>v;
    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        v.pb(x);
        mt[x] += 1;
    }
    set<pair<int,int>>st;
    int f, h;
    for(int i = 0; i < m; i++){
        cin >> f >> h;
        st.insert( mp(f , h) );
    }
    vector<int>pre(n+1, 0),suff(n+1, 0);
    for(int i = 0; i < n; i++){
        d[v[i]] += 1;
        pre[i] = d[v[i]];
        suff[i] = mt[v[i]] - d[v[i]] + 1; 
    }
    int i = 0;
    int maxi = 0*1ll;
    vector<int>ans( n+1 , 0);
    set<set<pair<int,int>>>final_set;
    while(i < n){
        int cal = 1;
        vector<int>visit(5001,0);
        set<pair<int,int>>temp = st;
        set<pair<int,int>>tp1, tp2, fin;

        for(int l = i ; l >= 0; l--){
            if(visit[v[l]] != 1){
                pair<int,int> p = mp(v[l],pre[l]);
                if(temp.find(p) != temp.end()){
                    temp.erase(p);
                    tp1.insert(p);
                    visit[v[l]] = 1;
                }
            }
        }
        vector<int>visit1(5001,0);
        for(int l = i + 1; l < n ;l++){
            if(visit1[v[l]] != 1){
                pair<int,int> p = mp(v[l],suff[l]);
                // if(st.find(p) != st.end()){
                //     tp2.insert(p);
                // }
                if(temp.find(p) != temp.end()){
                    temp.erase(p);      
                    visit1[v[l]] = 1;
                }
            }
        }
        int ch = st.size() - temp.size();
        maxi = max(maxi, ch);
        ans[maxi] += cal%MOD;
        i++;
    }
    cout << maxi << " "<<ans[maxi]<<endl;
}
//observations
/*

count the number of frquencies of every sweetness and find the non-overlaping 
sweetness intervals with maximum number of cows

so now problem is reduced to finding non overlapping intervals such that every 
interval  is representing one cow

so for all n^2 intervals assign every interval to all the cows no you cant do that 
it will  be n^2*5000 which is a lot
suppose some how you got the non overlapping intervals now what you will do  
to find the ways
not all the intervals but on prefix and suffix intervals
so now problem got reduced to finding all is and calculatig all prefix and suffix cows addin them up 
finding all the indexes where the answer was maximum

*/