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
int calculate(vector<int>&v,int l,int r){
    int cnt =0;
    int n=v.size();
    vector<int>pre(n+2,1),suff(n+2,1);
    for(int i=l;i<=r;i++){
        pre[i]=v[i]*pre[i-1];
    }
    for(int i=r;i>=l;i--){
        suff[i]=v[i]*suff[i+1];
    }
    for(int i=l;i<=r;i++){
        if(v[i]<0){
            cnt++;
        }
    }
    int k=r-l+1;
    if(k==1 and cnt==1){
        return pre[r];
    }
    else if(cnt%2==0){
        return pre[r];
    }else{
        int ans=-1e8;
        for(int i=l;i<=r;i++){
            if(v[i]<0){
                ans=max(max(pre[i-1],suff[i+1]),ans);
            }
        }
        return ans;
    }
}

int maxProduct(vector<int>& nums) {
    int n=nums.size();
    vector<int>v(n+1),zero;
    v[0]=1;
    zero.push_back(0);
    int cnt=0;
    for(int i=1;i<=n;i++){
        v[i]=nums[i-1];
        if(v[i]==0){
            zero.push_back(i);
        }
        if(v[i]>0){
            cnt++;
        }
    }
    zero.push_back(n+1);
    int l=1,r=1;
    vector<pair<int,int>>v1;
    int k=zero.size();
    for(int i=1;i<=k;i++){
        if(zero[i]-zero[i-1]>1){
            l=zero[i-1]+1;
            r=zero[i]-1;
            v1.push_back(make_pair(l,r));
        }
    }
    // tr(v1);
    int ans =-1e8;
    for(auto p:v1){
        ans=max(ans,calculate(v,p.fi,p.se));
    }   
    if(ans<0 and zero.size()>2){
        ans=0;
    }
    return ans;
}
int32_t main() {
    int n;
    cin>>n;
    vector<int>v;
    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        v.pb(x);
    }
    int p=maxProduct(v);
    tr(p);
}