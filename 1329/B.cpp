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
// #define int ll
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
const int MAXN = (1 << 18);

// template <class T>
struct fenwick
{
	int sz;
	int tr[MAXN];

	void init(int n)
	{
		sz = n + 1;
		memset(tr, 0, sizeof(tr));
	}

	int query(int idx)
	{
		int ans = 0;
		for(; idx >= 1; idx -= (idx & -idx))
			ans = ans+ tr[idx];
		return ans;
	}

	void update(int idx, int val)
	{
		if(idx <= 0) return;
		for(; idx <= sz; idx += (idx & -idx))
			tr[idx] = tr[idx]+ val;
	}

	// int query(int l, int r) { return query(r) - query(l - 1); }
};
int main() {
    RUN_T{
        int n;
        cin >> n;
        vector<int>v(n);
        for(int i = 0; i < n; i++){
            cin>>v[i];
        }
        fenwick* sgt1 = new fenwick();
        sgt1->init(n + 1);
        fenwick* sgt2 = new fenwick();
        sgt2->init(n + 1);
        vector<int>v1(n),v2(n);
        int len = 1;
        vector<int>vis2(n+1,0);
        for(int i = 0; i < n; i++){
            if(vis2[v[i]] == 0){
                sgt1->update(v[i], 1);
                int ans = sgt1->query(len);
                if( ans == len){
                    v1[i] = 1;
                }
                vis2[v[i]] = 1;
            }else{
                break;
            }
            len++;
        }
        // tr(v1);
        reverse(all(v));
        len = 1;
        vector<int>vis(n+1,0);
        for(int i = 0; i < n; i++){
            if(!vis[v[i]]){
                sgt2->update(v[i], 1);
                int ans = sgt2->query(len);
                if( ans == len){
                    v2[n - i - 1] = 1;
                }
                vis[v[i]] = 1;
            }else{
                break;
            }
            len++;
        }
        // tr(v2);
        vector<pair<int,int>>v3;
        for(int i = 0; i < n -1; i++){
            if(v1[i] == 1 and v2[i+1] == 1){
                v3.pb(mp(i + 1, n - i - 1));
            }
        }
        cout<< v3.size()<<endl;
        for(auto i: v3){
            cout<<i.fi <<" "<<i.se <<endl;
        }
    }
}