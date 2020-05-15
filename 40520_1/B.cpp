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
const int MAXN = 1000010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN];
int L1[MAXN], R1[MAXN];
int L2[MAXN], R2[MAXN];
stack<int> stk;

int32_t main(){
    _
	cin >> n;
	for (int i = 1; i <= n; i++){
        cin >> A[i], A[i]++;
    } 
	stk.push(0);
	for (int i = 1; i <= n; i++){
		while (A[stk.top()] > A[i]){
            stk.pop();
        }
		L1[i] = stk.top();
		stk.push(i);
	}
	while (stk.size()) stk.pop();
	
	A[0]=inf;
	stk.push(0);
	for (int i = 1; i <= n; i++){
		while (A[stk.top()] < A[i]){
            stk.pop();
        } 
		L2[i] = stk.top();
		stk.push(i);
	}
	while (stk.size()) stk.pop();
	
	A[n+1]=0;
	stk.push(n+1);
	for (int i = n; i; i--){
		while (A[stk.top()] >= A[i]) stk.pop();
		R1[i] = stk.top();
		stk.push(i);
	}
	while (stk.size()) stk.pop();
	
	A[n+1]=inf;
	stk.push(n+1);
	for (int i=n; i; i--){
		while (A[stk.top()]<=A[i]) stk.pop();
		R2[i]=stk.top();
		stk.push(i);
	}
	while (stk.size()) stk.pop();
	
	for (int i=1; i<=n; i++){
		ans+=(i-L2[i])*(R2[i]-i)*A[i];
		ans-=(i-L1[i])*(R1[i]-i)*A[i];
	}
	cout<<ans<<endl;
	
	return 0;
}

