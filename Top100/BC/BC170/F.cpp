#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef long long ll;
typedef long double lld;
typedef long long int lli;
using namespace std;
const int N = 1000001;
const int MOD = 1e9+7;
const bool DEBUG = 1;
#define sd(x) scanf("%d ", &x)
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
#define __			\
    freopen("input.txt", "r", stdin);			\
    freopen("output.txt", "w", stdout);
#define all(c) c.begin(), c.end()
#define inf 1000000000000000001
#define epsilon 1e-6
#define int ll
#define RUN_T			\
    int _t;			\
    cin >> _t;			\
    while (_t--)
#define tr(...)			\
if (DEBUG) {			\
    cout << __FUNCTION__ << ' ' << __LINE__ << " = ";			\
    trace(#__VA_ARGS__, __VA_ARGS__);			\
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
int32_t main(){
    int h, w, k;
    cin >> w >> h >> k;
    int x1, y1, x2, y2;
    cin >> x1 >>y1 >> x2 >> y2;
    x1--, x2--, y1--, y2--;
    vector<vector<char>>v(w , vector<char>(h, 0));
    vector<vector<int>>dp(w , vector<int>(h, 1e8));
    queue<pair<int,int>>q;
    for(int i = 0 ; i < w; i++){
        for(int j = 0; j < h; j++){
            cin >> v[i][j];
        }
    }
    map<pair<int,int>, int>vis;
    q.push(mp(x1,y1));
    vis[mp(x1,y1)] = 1;
    dp[x1][y1] = 1;
    while(!q.empty()){
        auto z = q.front();
        q.pop();
        int cnt1 = 0,cnt2 = 0;
        int x1 = z.fi, y1 = z.se;
        while(x1 + 1 < w and cnt1 < k){
            x1 += 1;
            cnt1++;
            if(v[x1][y1] == '@'){
                break;
            }
             dp[x1][y1] = min(dp[x1][y1] , dp[z.fi][z.se] + 1);
            if(vis[mp(x1 ,y1)] != 1){
                q.push(mp(x1, y1));
                vis[mp(x1, y1)] = 1;
            }
        }
        cnt1 = 0;
        x1 = z.fi, y1 = z.se;
        while(y1 + 1 < h and cnt1 < k){
            y1 += 1;
            cnt1++;
            if(v[x1][y1] == '@'){
                break;
            }
            dp[x1][y1] = min(dp[x1][y1] , dp[z.fi][z.se] + 1);
            if(vis[mp(x1 ,y1)] != 1){
                q.push(mp(x1, y1));
                vis[mp(x1, y1)] = 1;
            }
        }
        cnt1 = 0;
        x1 = z.fi, y1 = z.se;
        while(x1 - 1 >= 0 and cnt1 < k){
            x1 -= 1;
            cnt1++;
            if(v[x1][y1] == '@'){
                break;
            }
            dp[x1][y1] = min(dp[x1][y1] , dp[z.fi][z.se] + 1);
            if(vis[mp(x1 ,y1)] != 1){
                q.push(mp(x1, y1));
                vis[mp(x1, y1)] = 1;
            }
        }
        cnt1 = 0;
        x1 = z.fi, y1 = z.se;
        while(y1 - 1 >= 0 and cnt1 < k){
            y1 -= 1;
            cnt1++;
            if(v[x1][y1] == '@'){
                break;
            }
            dp[x1][y1] = min(dp[x1][y1] , dp[z.fi][z.se] + 1);
            if(vis[mp(x1 ,y1)] != 1){
                q.push(mp(x1, y1));
                vis[mp(x1, y1)] = 1;
            }
        }
    }
    // for(auto p:dp){
    //     tr(p);
    // }
    if(dp[x2][y2] >= 1e8){
        cout << -1 << endl;
    }else{
        cout << dp[x2][y2] - 1 << endl;
    }

}