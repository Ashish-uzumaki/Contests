// g++ -std=c++14

/*

Today might be the chance to grasp the chance to let your talent bloom.
May be tomorrow, the day after, or next year...
May be even when you are 30. I'm not sure if physique has anything to do with it
but if you think that it will never come, it probably never will.

- Tooru Oikawa.

*/


#include<bits/stdc++.h>

typedef long long ll;
typedef long double lld;
using namespace std;

#define endl "\n"
#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define MEMS(a,b) memset(a,b,sizeof(a))
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define all(c) c.begin(),c.end()
#define pii pair<int, int>
#define tr(...) cout<<_FUNCTION<<' '<<LINE<<" = ";trace(#VA_ARGS, __VA_ARGS_)
template<typename S, typename T>
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.fi<<", "<<p.se<<')';return out;}

template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
ll l=v.size();for(ll i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}

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

template<typename T>
void trace(const char* name, T&& arg1){cout<<name<<" : "<<arg1<<endl;}

template<typename T, typename... Args>
void trace(const char* names, T&& arg1, Args&&... args){
const char* comma = strchr(names + 1, ',');cout.write(names, comma-names)<<" : "<<arg1<<" | ";trace(comma+1,args...);}

#define int ll
vector<vector<int>> dp;
vector<vector<int>> arr;
int n, k, p;

int f(int i, int rem) {
    if (i == n + 1) {
        return 0;
    }
    int &ans = dp[i][rem];
    if (ans != -1) return ans;
    ans = 0;
    int curr_sum = 0;
    for (int j = 0; j <= k; j++) {
        if ((rem - j) >= 0) {
            if (j > 0) {
                curr_sum += arr[i][j - 1];
            }
            ans = max(ans, curr_sum + f(i + 1, rem - j));
        }
    }
    return ans;
}

int solve(int ts) {
    cin >> n >> k >> p;
    arr.clear();
    arr.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < k; j++) {
            int x;
            cin >> x;
            arr[i].push_back(x);
        }
    }
    dp.clear();
    dp = vector<vector<int>> (n + 1, vector<int> (p + 1, -1));

    cout << "Case #" << ts << ": ";
    cout << f(1, p) << endl;
    return 0;
}

int32_t main(){ _
    int t;
    cin >> t;
    // t = 1;
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}