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
const int MAXN = (int)4e3 + 42;
// const int inf = (int)1e9 + 42;
int dp[MAXN][MAXN], cost[MAXN][MAXN];
  int n,m;
void calc_cost(string s){
    for(int l = 2; l <= s.size(); l++){
        for(int i = 0; i + l <= s.size(); i++){
            int j = i+l-1;
            if(s[i] == s[j]){
                if(i+1 <= j-1){
                    cost[i][j] = cost[i+1][j-1];
                }else{
                    cost[i][j] = 0;
                }
            }else{
                if(i+1 <= j-1){
                    cost[i][j] = cost[i+1][j-1] + 1;
                }else{
                    cost[i][j] = 1;
                }
            }
        }
    }
}

void rec(int l, int r, int opt_l, int opt_r, int k)
{
	if(r < l) return;

	if(l == r)
	{
		dp[l][k] = inf;
		for(int i = opt_l; i <= min(opt_r, l); i++)
			if(dp[l][k] > dp[i - 1][k - 1] + cost[i-1][l-1])
				dp[l][k] = dp[i - 1][k - 1] + cost[i-1][l-1];

		return;
	}

	int mid = (l + r) >> 1, copt = opt_l;

	dp[mid][k] = inf;
	for(int i = opt_l; i <= min(mid, opt_r); i++)
		if(dp[mid][k] > dp[i - 1][k - 1] + cost[i-1][mid-1])
		{
			dp[mid][k] = dp[i - 1][k - 1] + cost[i-1][mid-1];
			copt = i;
		}

	rec(l, mid - 1, opt_l, copt, k);
	rec(mid + 1, r, copt, opt_r, k);
}

void solve()
{
	for(int i = 0; i <= n; i++) dp[i][0] = inf;
	for(int i = 0; i <= m; i++) dp[0][i] = 0;
	for(int k = 1; k <= m; k++)
		rec(1, n, 1, n, k);
}

int32_t main() {
    _
    cin >> n >> m;
    string s;
    cin>>s;
    calc_cost(s);
    solve();
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cout<<dp[i][j]<<" \n"[j==m];
        }
    }
    // cout<<dp[n][m];
}
//   for (int K = 2; K <= k; K++) {
//         for (int i = 0; i + K <= s.size(); i++) {
//             dp2[i][K] = INT_MAX;
//             for (int m = i; m + K <= s.size() ; m++) {
// // number of moves to make s[i..end] to K palindromes = 
// // min (number of moves to make s[i..m] to 1 palindromes  + number of moves to make s[m+1..end] to K-1 palindromes)
// // for m in [i..end-1]
// // beacasue s[i] must belong to one palindrome
//                 dp2[i][K] = min(dp2[i][K], dp1[i][m] + dp2[m+1][K-1]);
//             }
//         }
//     }