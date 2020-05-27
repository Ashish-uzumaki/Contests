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

int n, m;
// int a[MAXN];

struct node
{
	int sum;

	node() {sum = 0;}
	node(int val)
	{
		sum = val;
	}
};

node temp, broken;

node merge(node l, node r)
{
	temp.sum = l.sum + r.sum;
	return temp;
}

struct segment_tree
{
	node tr[4 * MAXN];

	void init(int l, int r, int idx, vector<int>&a)
	{
		if(l == r)
		{
			tr[idx] = node(a[l]);
			return;
		}

		int mid = (l + r) >> 1;
		init(l, mid, 2 * idx + 1,a);
		init(mid + 1, r, 2 * idx + 2,a);

		tr[idx] = merge(tr[2 * idx + 1], tr[2 * idx + 2]);
	}

	void update(int pos, int val, int l, int r, int idx)
	{
		if(l > pos || r < pos)
			return;

		if(l == r && l == pos)
		{
			tr[idx].sum = val;
			return;
		}

		int mid = (l + r) >> 1;
		update(pos, val, l, mid, 2 * idx + 1);
		update(pos, val, mid + 1, r, 2 * idx + 2);

		tr[idx] = merge(tr[2 * idx + 1], tr[2 * idx + 2]);
	}

	node query(int qL, int qR, int l, int r, int idx)
	{
		if(l > qR || r < qL)
			return broken;

		if(qL <= l && r <= qR)
			return tr[idx];

		int mid = (l + r) >> 1;
		return merge(query(qL, qR, l, mid, 2 * idx + 1), query(qL, qR, mid + 1, r, 2 * idx + 2));
	}
};
vector<int> recalc_pref(vector<int>A){
    int n = A.size();
    vector<int>pref(n, 0);
    int sig  = 1;
    for(int i = 0 ; i < n; i++){
        if(i % 2 == 0){
            sig = 1;
        }else{
            sig = -1;
        }
        pref[i] = sig*A[i]*(i+1);
    }
    return pref;
}
vector<int> recalc_pref2(vector<int>A){
    int n = A.size();
    vector<int>pref(n, 0);
    int sig = 1;
    for(int i = 0 ; i < n; i++){
        if(i % 2 == 0){
            sig = 1;
        }else{
            sig = -1;
        }
        pref[i] = sig*A[i] + pref[i];
    }
    return pref;
}
int32_t main() {
    int te;
    cin >> te;
    for(int t = 1 ; t <= te; t++){
        int n, m;
        cin  >> n >> m;
        vector<int>v(MAXN);
        for(int i = 0; i < n; i++){
            cin>>v[i];
        }
        vector<int>pref_A,pref_B;
        pref_A = recalc_pref(v);
        pref_B = recalc_pref2(v);
        segment_tree *t1 = new segment_tree();
        segment_tree *t2 = new segment_tree();
        t1->init(0 , n - 1, 1 ,pref_A);
        t2->init(0 , n - 1, 1 ,pref_B);
        char c;
        int x, y;
        int cnt = 0;
        for(int i = 0 ;i <  m; i++){
            cin >> c >> x >> y;
            x--;
            if(c == 'Q'){
                y--;
                node p1 = t1->query(x, y, 0, n-1, 1);
                node p2 = t2->query(x, y, 0, n-1, 1);
                int val1 = p1.sum;
                int val2 = x * p2.sum;
                val2  = val1 - val2;
                // tr(val1, val2);
                if(x % 2 == 1){
                    val2 = val2 * (-1);
                }
                // tr(val2);
                cnt += val2;
            }else{
                int sig  = 1;
                if( x % 2 == 1){
                    sig = -1;
                }
                int val = sig * (x + 1) * y;
                int val1 = sig*y;
                // tr(val,val1);
                t1->update( x, val, 0 , n-1, 1);
                t2->update( x, val1, 0 , n-1, 1);

            }
        }
        cout <<"Case #"<<t<<": " <<cnt << endl;
        
    }
}