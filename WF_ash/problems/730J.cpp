
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
#define tr(...) cout<<__FUNCTION__<<' '<<__LINE__<<" = ";trace(#__VA_ARGS__, __VA_ARGS__)

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
typedef pair <ll, ll> pll;

const int N = 2e5 + 10, mod = 1e9 + 7, inf = 1e9 + 42;
// p[i] = rank of ith suffix!!!!

struct SuffixArray {
  const int L;
  vector<int> s;
  vector<vector<int> > P;
  vector<pair<pair<int,int>,int> > M;

  SuffixArray(const vector<int> &s) : L(s.size()), s(s), P(1, vector<int>(L, 0)), M(L) {
    for (int i = 0; i < L; i++) P[0][i] = int(s[i]);
    for (int skip = 1, level = 1; skip < L; skip *= 2, level++) {
      P.push_back(vector<int>(L, 0));
      for (int i = 0; i < L; i++)
             M[i] = make_pair(make_pair(P[level-1][i], i + skip < L ? P[level-1][i + skip] : -1000), i);
      sort(M.begin(), M.end());
      for (int i = 0; i < L; i++)
             P[level][M[i].second] = (i > 0 && M[i].first == M[i-1].first) ? P[level][M[i-1].second] : i;
    }
  }

  vector<int> GetSuffixArray() { return P.back(); }
  vector<int> GetInvSuffixArray() {
      vector<int> ans(s.size());
      auto p = GetSuffixArray();
      for (int i = 0; i < (int)s.size(); i++) {
          ans[p[i]] = i;
      }
      return ans;
  }
  // returns the length of the longest common prefix of s[i...L-1] and s[j...L-1]
  int LongestCommonPrefix(int i, int j) {
    int len = 0;
    if (i == j) return L - i;
    for (int k = P.size() - 1; k >= 0 && i < L && j < L; k--) {
      if (P[k][i] == P[k][j]) {
        i += 1 << k;
        j += 1 << k;
        len += 1 << k;
      }
    }
    return len;
  }
};

vector<int> lcp_construction(vector<int> const& s, vector<int> const& p) {
    int n = s.size();
    vector<int> rank(n, 0);
    for (int i = 0; i < n; i++)
        rank[p[i]] = i;

    int k = 0;
    vector<int> lcp(n-1, 0);
    for (int i = 0; i < n; i++) {
        if (rank[i] == n - 1) {
            k = 0;
            continue;
        }
        int j = p[rank[i] + 1];
        while (i + k < n && j + k < n && s[i+k] == s[j+k])
            k++;
        lcp[rank[i]] = k;
        if (k)
            k--;
    }
    return lcp;
}

const int LOG = 25;

int solve() {
    int n;
    vector<int> arr;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp; cin >> temp;
        arr.push_back(temp);
    }
    vector<int> dp(n + 1);
    vector<vector<int>> nxt(n + 1, vector<int> (LOG, 0));
    vector<vector<int>> cont(n + 1, vector<int> (LOG, 0));
    stack<int> s;
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && arr[s.top()] < arr[i]) s.pop();
        if (s.empty()) {
            dp[i] = (n - i) * arr[i];
            nxt[i][0] = n;
            cont[i][0] = (n - i) * arr[i];
        } else {
            dp[i] = (s.top() - i) * arr[i] + dp[s.top()];
            nxt[i][0] = s.top();
            cont[i][0] = (s.top() - i) * arr[i];
        }
        // tr(i, nxt[i][0]);
        s.push(i);
    }
    while(!s.empty()) s.pop();
    for (int i = 0; i < LOG; i++) {
        nxt[n][i] = n;
    }
    for (int i = 1; i < LOG; i++) {
        for (int j = 0; j < n; j++) {
            int lol = nxt[j][i - 1];
            nxt[j][i] = nxt[lol][i - 1];
            cont[j][i] = cont[j][i - 1] + cont[lol][i - 1];
            tr(nxt[j][i], j, i);
        }
    }
    SuffixArray sa(arr);

    auto inv_sa = sa.GetInvSuffixArray();


    auto lcp = lcp_construction(arr, inv_sa);
    tr(lcp, inv_sa);
    // tr(inv_sa, lcp);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int ind = inv_sa[i];
        ans += dp[ind];
        if (i) {
            int len = lcp[i];
            int curr = ind;
            for (int j = LOG - 1; j >= 0; j--) {
                int qq = nxt[curr][j];
                if ((qq - ind) <= len) {
                    ans -= cont[curr][j];
                    curr = qq;
                }
            }
            tr(curr);
            int rem = ind + len - curr;
            ans -= rem * arr[curr];
        }
        tr(i, ind, ans);
    }
    cout << ans << endl;
    return 0;
}


int32_t main(){ 
    int t;
    cin >> t;
    while (t--) solve();
}