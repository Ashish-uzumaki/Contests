#include <algorithm>
#include <numeric>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>
 
using namespace std;
 
typedef long long ll;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef pair<int, int> PII;
 
 
#define FOR(i, x, y) for(ll i=x; i<=y; i++)
#define FORD(i, x, y) for (ll i = x; i >= y; --i)
#define REP(i, n) for(ll i=0; i<n; i++)
#define REPD(i, n) for(ll i = n - 1; i >= 0; --i) 
 
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))
#define UNIQ(c) SORT(c),(c).resize(unique(ALL(c))-(c).begin())
#define SZ(c) (int)(c).size()
 
#define CLEAR(x) memset(x,0,sizeof x)
#define FILL(x,v) memset(x,v,sizeof x)
 
#define pb push_back
#define mp make_pair
#define X first
#define Y second
 
 
 
const double eps = 1.0e-11;
const double pi = acos(-1.0);
vector<vector<int> > g;
vector<bool> u;
vector<int> pred;
vector<int> d;
int n, m, k;
bool ok = false;
int ed, len;
 
void dfs(int v, int p, int depth) {
    if (ok)
        return;
    u[v] = true;
    d[v] = depth;
    pred[v] = p;
 
    REP(i, SZ(g[v])) {
        if (ok)
            return;
        int to = g[v][i];
        if (u[to]) {
            if (depth - d[to] >= k) {
                ok = true;
                ed = v;
                len = depth - d[to];
                return;
            }
        } else {
            dfs(to, v, depth + 1);
        }
    }
}
 
int main() {
    
    cin >> n >> m >> k;
    g.resize(n);
    u.resize(n);
    pred.resize(n);
    d.resize(n);
    REP(i, m) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
 
    REP(i, n) {
        if (ok)
            break;
        dfs(i, - 1, 0);
    }
    cout << len + 1 << endl;
    REP(i, len + 1) {
        cout << ed + 1 << " ";
        ed = pred[ed];
    }
 
    return 0;
}