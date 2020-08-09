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
int32_t main() {
    _
    int n, m, k;
    cin >> n >> m >> k;
    m--,n--;
    vector< pair<int, string>> v;
    if(n==0){
        int l = m;
        int r = m;
        while(r > 0 and k > 0){
                r--;
                k--;
        }
        if(m - r > 0){
            v.pb(mp(m-r,"R"));
        }
        while(l > 0 and k > 0){
            l--;
            k--;
        }
        if( m - l > 0){
            v.pb(mp(m-l,"L"));
        }
    }
    else if(m==0){
        int l = n;
        int r = n;
        // tr("yo",l,r);
        while(r > 0 and k > 0){
                r--;
                k--;
        }
        if(n - r > 0){
            v.pb(mp(n-r,"D"));
        }
        while(l > 0 and k > 0){
            l--;
            k--;
        }
        if( n - l > 0){
            v.pb(mp(n-l,"U"));
        }
    }else{
        //for first row
        int r = m;
        int l = m;
        if(k > 0){
            while(r > 0 and k > 0){
                r--;
                k--;
            }
            if(m - r > 0){
                v.pb(mp(m-r,"R"));
            }
            while(l > 0 and k > 0){
                l--;
                k--;
            }
            if(m-l > 0){
                v.pb(mp(m - l, "L"));
            }
            if(k > 0){
                v.pb(mp(1,"D"));
                k--;
            }
        }
        int t = 1;
        while(k > 0 and t <= n){
            int r = m; 
            int l = m;
            while(r > 0 and k > 0){
                r--;
                k--;
            }
            if(m - r > 0){
                v.pb(mp(m-r,"R"));
            }
            int p = 3, cnt = 0;
            while(k > 0 and l > 0){
                string s = "";
                s+='U';
                k--;
                if(k > 0){
                    s+='D';
                    k--;
                }
                if(k > 0){
                    s+='L';
                    l--;
                    k--;
                }
                if(s.size() == p){
                    cnt++;
                    int x = v.size()-1;
                    auto g = v[x];
                    if(g.se == s){
                        v[x].fi += 1;
                    }else{
                        v.pb(mp(1,s));
                    }
                }else{
                    v.pb(mp(1,s));
                }
            }
            if(k > 0 and t != n){
                v.pb(mp(1,"D"));
                k-=1;
            }
            if(t == n ){
                int h = n;
                while( k > 0 and h > 0){
                    h--;k--;
                }
                if(n - h > 0){
                    v.pb(mp(n - h,"U"));
                }
            }
            t++;
        }
    }
    if(k>0){
        cout<<"NO"<<endl;
    }else{
        cout<<"YES"<<endl;
        cout << v.size() << endl;
        for(auto p: v){
            cout<< p.fi <<" "<< p.se <<endl; 
        }
    }
}