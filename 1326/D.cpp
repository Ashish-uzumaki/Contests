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
int longestPrefixSuffix(string s) 
{ 
    int n = s.length(); 
  
    int lps[n]; 
    lps[0] = 0;
    int len = 0; 
    int i = 1; 
    while (i < n) 
    { 
        if (s[i] == s[len]) 
        { 
            len++; 
            lps[i] = len; 
            i++; 
        } 
        else {  
            if (len != 0) 
            { 
                len = lps[len-1];  
            } 
            else // if (len == 0) 
            { 
                lps[i] = 0; 
                i++; 
            } 
        } 
    } 
  
    int res = lps[n-1];  
    return (res > n/2)? n/2 : res; 
}
string compute(string s){
    string s1 = s;
    string s2 = s1;
    
    reverse(all(s2));
    
    string p ="";
    p+=s1;
    p+="0";
    p+="1";
    p+=s2;
    int len = longestPrefixSuffix(p);
    string pro ="";

    for(int i =0 ; i < len ;i++){
        pro+=p[i];
    }
    p="";
    p+=s2;
    p+="0";
    p+="1";
    p+=s1;
    int len1 = longestPrefixSuffix(p);
    string pro1 ="";
    for(int i = 0 ; i < len1 ;i++){
        pro1+=p[i];
    }
    if(len > len1){
            pro1 = pro; 
    }
    return pro1;
}
int32_t main() {
    RUN_T{
        string s;
        cin >> s;
        int n = s.length();
        int r = n - 1;
        string ans1 ="", ans2 ="",ans ="";
        int idx  = -1;
        if( n == 1){
            cout<< s << endl;
            continue;
        }
        for(int i = 0 ;i < n; i++){
            if(s[i] == s[r] and i < r){
                ans1 += s[i];
                ans2 += s[r];
                r--;
            }else{
                idx = i;
                break;
            }
        }
        string pro ="";
        // tr(r);
        if(idx >= 0){
            string s1 = s.substr(idx,r-idx+1);
            // tr(s1);
            pro = compute(s1);
        }
        // tr(pro,ans1,ans2);
        if(ans1!=""){
            ans+=ans1;
            ans+=pro;
            reverse(all(ans2));
            ans+=ans2;
        }
        string pro1 = compute(s);
        if(pro1.length()> ans.length()){
            ans = pro1;
        }
        cout<<ans<<endl;
    }
}