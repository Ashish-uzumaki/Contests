// g++ -std=c++14

#include <bits/stdc++.h>

typedef long long ll;
typedef long double lld;
typedef long long int lli;
using namespace std;
const int N = 10000001;
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
#define _                                                                      \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);
#define __                                                                     \
  freopen("input.txt", "r", stdin);                                            \
  freopen("output.txt", "w", stdout);
#define all(c) c.begin(), c.end()
#define inf 1000000000000000001
#define epsilon 1e-6

#define RUN_T                                                                  \
  int _t;                                                                      \
  cin >> _t;                                                                   \
  while (_t--)

#define tr(...)                                                                \
  if (DEBUG) {                                                                 \
    cout << __FUNCTION__ << ' ' << __LINE__ << " = ";                          \
    trace(#__VA_ARGS__, __VA_ARGS__);                                          \
  }

template <typename S, typename T>
ostream &operator<<(ostream &out, pair<S, T> const &p) {
  out << '(' << p.fi << ", " << p.se << ')';
  return out;
}

template <typename T> ostream &operator<<(ostream &out, set<T> const &v) {
  for (auto i = v.begin(); i != v.end(); i++)
    out << (*i) << ' ';
  return out;
}

template <typename T, typename V>
ostream &operator<<(ostream &out, map<T, V> const &v) {
  for (auto i = v.begin(); i != v.end(); i++)
    out << "\n" << (i->first) << " : " << (i->second);
  return out;
}

template <typename T, typename V>
ostream &operator<<(ostream &out, unordered_map<T, V> const &v) {
  for (auto i = v.begin(); i != v.end(); i++)
    out << "\n" << (i->first) << " : " << (i->second);
  return out;
}

template <typename T> ostream &operator<<(ostream &out, multiset<T> const &v) {
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
  cout << name << " : " << arg1 << endl;
}

template <typename T, typename... Args>
void trace(const char *names, T &&arg1, Args &&... args) {
  const char *comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1 << " | ";
  trace(comma + 1, args...);
}

int gcd(int a, int b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

#define int ll

// __builtin_popcount -> count number of bits
int mod = 1e9 + 7;

int power(int x, int y) {
    int res = 1;
    x = x % mod;
    while (y > 0) {
        if (y & 1){
            res = (res*x) % mod;
        }
        y = y>>1;
        x = (x*x) % mod;
    }
    return res;
}
vector<int>dp(N,1);
void preprocess(){
    for(int i=2;i<=N-1;i++){
        dp[i]=(dp[i-1]*i)%mod;
    }
}
int32_t main() {
    _
    preprocess();
    RUN_T{
        int n;
        cin>>n;
        string s1,s2;
        cin>>s1>>s2;
        int cnt1=0,cnt2=0;
        for(int i=0;i<s1.size();i++){
            if(s1[i]=='1'){
                cnt1++;
            }
        }
        for(int i=0;i<s2.size();i++){
            if(s2[i]=='1'){
                cnt2++;
            }
        }
        int diff=abs(cnt2-cnt1);
        int cumm=cnt1+cnt2;
        if(cumm>n){
            cumm=2*n-cumm;
        }
        int ans =0;
        for(int i=diff;i<=cumm;i+=2){
            int tem=dp[n];
            tem = tem * power(dp[i], mod-2);
            tem%=mod;
            tem = tem * power(dp[n - i], mod-2);
            tem%=mod;
            ans = (ans + tem) % mod;
        }
        cout<<ans<<endl;
    }
}

