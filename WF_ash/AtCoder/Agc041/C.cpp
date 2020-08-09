#include <bits/stdc++.h>
typedef long long ll;
typedef long double lld;
typedef long long int lli;
using namespace std;
const int N = 1000001;
const bool DEBUG = 1;
#define sd(x) scanf("%d", &x)
#define sd2(x, y) scanf("%d%d", &x, &y)
#define sd3(x, y, z) scanf("%d%d%d", &x, &y, &z)
#define endl "\n"
#define fi first
#define se second
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
int gcd(int a, int b) {
     if (b == 0)
        return a;
    return gcd(b, a % b);
}
#define int ll
map<int, vector<string>> memo = {
	{3,
		{"a..",
		 "a..",
		 ".bb"}
	},
	{4,
		{"abcc",
		 "abdd",
		 "eegh",
		 "ffgh"}
	},
	{5,
		{"abbcc",
		 "ai..d",
		 "fi..d",
		 "f.jje",
		 "gghhe"}
	},
	{6,
		{"aabc..",
		 "ddbc..",
		 "..aabc",
		 "..ddbc",
		 "bc..aa",
		 "bc..dd"}
	},
	{7,
		{"a..a..f",
		 "a..a..f",
		 ".bb.bbg",
		 "a..a..g",
		 "a..a..h",
		 ".bb.bbh",
		 "ccddee."}
	},
	{11,
		{"a..a..f....",
		 "a..a..f....",
		 ".bb.bbg....",
		 "a..a..g....",
		 "a..a..h....",
		 ".bb.bbh....",
		 "ccddee.....",
		 ".......abcc",
		 ".......abdd",
		 ".......eegh",
		 ".......ffgh"}
	}
};

int32_t main() {
    int n;
    cin >> n;
    
    int p = n;
    int x = 0;
    while (p > 7) {
        x++;
        p-=4;
    }
    // tr(x);
    int y = n - 4 * x;
    vector<string> ans;
    // x-=1;
    for( int i = 0; i < x; i++ ){
        for(int k = 0; k < 4 ; k++){
            ans.pb(memo[4][k]);
        }
    }
    x-=1;
    for(int i = 0; i < ans.size() ; i++){
        string s = ans[i];
        for(int j = 0 ; j < x ; j++){
            ans[i] += s;//resolve this error
        }
    }
    // tr(ans);
    int m = ans.size();
    tr(y);
    for( int i = 0; i < y ; i++ ){
        ans.pb( memo[y][i] );
    }
    int j=0;
    for(int i=0;i<m;i++){
        ans[i]+=memo[y][j];
        j=(j+1)%y;
    }

    // tr(ans);
    int r=y;
    for( int i = m; i < m + y ; i++ ){
        string s = memo[r][i-m];
        tr(s);
        for( int j = 0 ; j < m + y ; j++ ){
            ans[i] += s;
        }
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }
    // tr(ans);
    // tr(ans.size());
    // tr(ans[0].size());
    //now add extra strings of size y in both ans.pb() and ans+=y;
}