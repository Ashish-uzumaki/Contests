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
map<int,int>a1,b1,c1,m;
int mini=1e9;
int func1(int f){
    int ans1=0,ans2=0;
    map<int,int>a2=a1;
    for(int j=0;j<26;j++){
            a2[j]-=f*b1[j];
        }
        ans1+=f;
        mini=1e9;
        for(int j=0;j<26;j++){
            if(c1[j]>0){
                mini=min(mini,a2[j]/c1[j]);
            }
        }
        ans2+=mini;
        return ans1+ans2;
}

int32_t main() {
    _
    string a,b,c;
    cin>>a>>b>>c;
    int n=a.length();
    for(int i=0;i<n;i++){
        a1[a[i]-'a']+=1;
    }
    for(int i=0;i<b.length();i++){
        b1[b[i]-'a']+=1;
    }
    for(int i=0;i<c.length();i++){
        c1[c[i]-'a']+=1;
    }
    int iter=1e6;
    for(auto &t:b1){
        iter=min(iter,a1[t.fi]/t.se);
    }
    int maxi=-1,cnt1=0,cnt2=0;
    for(int i=0;i<=iter;i++){
        int x=func1(i);
        if(x>=maxi){
            maxi=x;
            cnt1=i;
            cnt2=x-i;
        }
    }
    // cout<<cnt1<<" "<<cnt2<<endl;
        string s="";
    for(int j=0;j<26;j++){
        a1[j]=a1[j]-cnt1*b1[j]-cnt2*c1[j];
    }
    for(int j=0;j<cnt1;j++){
        s+=b;
    }
    for(int j=0;j<cnt2;j++){
        s+=c;
    }
    // cout<<s<<endl;
    for(int j=0;j<26;j++){
        while(a1[j]>0){
            s+=(j+'a');
            a1[j]--;
        }
    }
    cout<<s<<endl;
}
