// g++ -std=c++14

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

int32_t main() {
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    map<int,int>m;
    m[0]=a;
    m[1]=b;
    m[2]=c;
    m[3]=d;
    int n=a+b+c+d;
    vector<int>v;
    for(int i=0;i<=3;i++){
        if(m[i]>0){
            v.pb(i);
            m[i]-=1;
            break;
        }
    }
    for(int i=1;i<n;i++){
             int x=v.back();
             if(m[x-1]>0){
                 m[x-1]-=1;
                 v.pb(x-1);
             }else if(m[x+1]>0){
                 m[x+1]-=1;
                 v.pb(x+1);
             }   
    }
    // for(auto i:v){
    //     cout<<i<<" ";
    // }
    if(m[0]==0 and m[1]==0 and m[2]==0 and m[3]==0){
        cout<<"YES"<<endl;
        for(auto j:v){
            cout<<j<<" ";
        }
        cout<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}
