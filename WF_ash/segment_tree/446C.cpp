#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef long long ll;
typedef long double lld;
typedef long long int lli;
using namespace std;
const int N = 1000001;
const int MOD=1e9+9;
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
int fib[N];

void creat_fibo(){
    
    fib[1]=1;
    fib[2]=1;

    for(int i=3;i<N;i++){
        fib[i] = (fib[i-1] + fib[i-2]) % MOD;
    }
}

int get_Kth_fibonacii(int a,int b,int k){
    
    a %= MOD;
    b %= MOD;
    
    if(k==1) return a;
    if(k==2) return b;
    
    return (( a * fib[k-2] ) % MOD +  (b * fib[k-1])  % MOD) % MOD ;
}

const int MAXN = (1 << 19);

int n, m;
int a[MAXN];
struct node{
	int sum; 
    pair< int , int> lazy;

	node() {sum = 0; lazy.fi = 0; lazy.se = 0;}
	node(int val){
		sum = val;
		lazy.fi = 0;
        lazy.se = 0;
	}
};

node temp, broken;

node merge(node l, node r){
	temp.sum = (l.sum + r.sum) % MOD;
	temp.lazy.fi = 0;
    temp.lazy.se = 0;
	return temp;
}

struct segment_tree{
	node tr[4 * MAXN];

	void push(int l, int r, int idx){
		if(tr[idx].lazy.fi>0 and tr[idx].lazy.se>0){
			
            int k=(r-l+1);

             //sum of fib[1]+fib[2]+...+fib[len]=fib[len+2]-fib[2];

            tr[idx].sum = (tr[idx].sum + ((get_Kth_fibonacii( tr[idx].lazy.fi, tr[idx].lazy.se,k+2)-tr[idx].lazy.se)%MOD + MOD) % MOD) % MOD;
			
            if(l != r){

				tr[2 * idx + 1].lazy.fi = (tr[2 * idx + 1].lazy.fi + tr[idx].lazy.fi) % MOD;
                tr[2 * idx + 1].lazy.se = (tr[2 * idx + 1].lazy.se + tr[idx].lazy.se) % MOD;

                int mid = (r + l) / 2;

				tr[2 * idx + 2].lazy.fi = (tr[2 * idx + 2].lazy.fi + get_Kth_fibonacii( tr[idx].lazy.fi ,tr[idx].lazy.se, mid-l+1+1)) % MOD;
				tr[2 * idx + 2].lazy.se = (tr[2 * idx + 2].lazy.se + get_Kth_fibonacii( tr[idx].lazy.fi ,tr[idx].lazy.se, mid-l+1+2)) % MOD;
    
            }
			tr[idx].lazy.fi = 0;
            tr[idx].lazy.se = 0;
		}
	}
    //start with 0,n-1,1 will work for 0 based indexing
	void init(int l, int r, int idx){
		if(l == r){
			tr[idx] = node(a[l]);
			return;
		}

		int mid = (l + r) >> 1;
		init(l, mid, 2 * idx + 1);
		init(mid + 1, r, 2 * idx + 2);

		tr[idx] = merge(tr[2 * idx + 1], tr[2 * idx + 2]);
	}

	void update(int qL, int qR, int val, int l, int r, int idx){
		push(l, r, idx);

        //fully outside query
		if(qL > r || l > qR)
			return;

        //fully inside
		if(qL <= l && r <= qR){
			tr[idx].lazy.fi = fib[l-qL+1];
            tr[idx].lazy.se = fib[l-qL+2];
			push(l, r, idx);
			return;
		}

        //partially inside
		int mid = (l + r) >> 1;
		update(qL, qR, val, l, mid, 2 * idx + 1);
		update(qL, qR, val, mid + 1, r, 2 * idx + 2);

		tr[idx] = merge(tr[2 * idx + 1], tr[2 * idx + 2]);
	}

	node query(int qL, int qR, int l, int r, int idx){
		push(l, r, idx);

		if(l > qR || r < qL)
			return broken;

		if(qL <= l && r <= qR)
			return tr[idx];

		int mid = (l + r) >> 1;
		return merge(query(qL, qR, l, mid, 2 * idx + 1), query(qL, qR, mid + 1, r, 2 * idx + 2));
	}
};

segment_tree t;

int32_t main() {
    _
    creat_fibo();
    int n,q,l,r,typ;
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    t.init(0,n-1,1);
    // tr("yo");
    for(int i=0;i<q;i++){
        cin>>typ>>l>>r;
        --l,--r;
        if(typ==1){
            // int x=F[i-l];
            t.update(l,r,1,0,n-1,1);
        }else{
            node ans = t.query(l ,r ,0 ,n-1, 1 );
            cout<<ans.sum<<endl;
        }
    }
}