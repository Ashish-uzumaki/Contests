#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
using VI = vector<int>;
 
const int N = 505;
int red[N][N], a[N], best[N][N];
 
int main() {
#ifdef LOCAL_EXEC
//	freopen("sample.in", "r", stdin);
//	freopen("sample.out", "w", stdout);
#else
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif
 
  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
 
  for (int len = 1; len <= n; len++) {
    for (int l = 0; l + len <= n; l++) {
      int r = l + len - 1;
      if (l == r) {
        red[l][r] = a[l];
        continue;
      }
      red[l][r] = -1;
      for (int k = l; k < r; k++) {
        int u = red[l][k], v = red[k + 1][r];
        if (u > 0 && v > 0 && u == v) {
          red[l][r] = u + 1;
          break;
        }
      }
    }
  }
 
  for (int len = 1; len <= n; len++) {
    for (int l = 0; l + len <= n; l++) {
      int r = l + len - 1;
      if (red[l][r] > 0) {
        best[l][r] = 1;
        continue;
      }
      best[l][r] = len;
      for (int k = l; k < r; k++) {
        best[l][r] = min(best[l][r], best[l][k] + best[k + 1][r]);
      }
    }
  }
  for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
          cout<< best[i][j]<<" ";
      }
      cout<<endl;
  }
  cout << best[0][n - 1] << endl;
 
  return 0;
}