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
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
vector<vector<int>>visit;
int n, m;
bool inside(int x,int y){
    if(x < 0 or y < 0 or x >= n or y >= m){
        return false;
    }
    return true;
}
vector<vector<char>>v;
void dfs(int x,int y){
    if(visit[x][y])
        return;
    visit[x][y]=1;
    for(int i=0;i<4;i++){
        if(inside(x + dx[i],y + dy[i]) && v[x+dx[i]][y+dy[i]] != '#'){
            dfs(x + dx[i], y + dy[i]);
        }
    }
}
void block(){
    // tr(n, m);
    for(int i = 0 ;i < n; i++){
        for(int j  = 0 ; j < m; j++){
            if(v[i][j] == 'B'){
                for(int k = 0;k < 4; k++){
                    if(inside(i + dx[k],j + dy[k]) && v[i + dx[k]][j + dy[k]] == '.'){
                        // tr(i + dx[k] , j + dy[k]);
                        v[i + dx[k]][j + dy[k]] = '#';
                    }
                }
            }
        }
    }
}
int32_t main(){
    _
    RUN_T{
        cin >> n >> m;
        v.clear();
        visit.clear();
        v.resize(n , vector<char>(m, '.'));
        visit.resize(n, vector<int>(m , 0));
        string s;
        for(int i = 0 ; i < n; i++){
            cin >> s;
            for(int j = 0; j < s.length(); j++){
                v[i][j] = s[j];
            }
        }
        // tr("yo");
        block();
        // for(int i = 0 ; i < n; i++){
        //     for(int j = 0; j < m; j++){
        //         cout << v[i][j];
        //     }
        //     cout << endl;
        // }
        if(v[n - 1][m - 1] != '#'){
            dfs(n - 1 , m - 1);
        }
        int flag = 0;
        // for(int i = 0 ; i < n; i++){
        //     for(int j = 0; j < m; j++){
        //         cout << visit[i][j];
        //     }
        //     cout << endl;
        // }
        for(int i = 0 ; i < n; i++){
            for(int j = 0; j < m; j++){
                if(v[i][j] == 'G' and visit[i][j] == 0){
                    flag = 1;
                    break;
                }
                if(v[i][j] == 'B' and visit[i][j] == 1){
                    flag = 1;
                    break;
                }
            }
        }
        if(flag) cout << "No"<<endl;
        else cout << "Yes"<< endl;
    }
}