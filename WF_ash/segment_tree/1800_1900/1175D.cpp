#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define lli long long int
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define se second;
#define fi first;
#define endl '\n';
#define MAXN 1005
#define INF 1e18
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define REP(i,n) for (int i = 1; i <= n; i++)
typedef long long ll;
typedef vector<vector<ll> > matrix;
const ll MOD = 1000000007;
const int K = 9;
const lli mod = 1e9 + 7;
// const lli N=2*1e6;
#define N 5009
bool Q;
ll inf=1e16;
int a[N];
lli dp[N][N];
int c[N][N];
int n,m,t;
void initialize(){
  for(int j = 1; j <= n; j++){
    dp[1][j] = c[1][j];
  }
}
void cost(){
  for(lli i=1; i<=n; i++){
            c[i][i]=a[i];
            for(lli j=i+1; j<=n; j++){
                c[i][j]=c[i][j-1]|a[j];
            }
        }
}
void calculate(int i, int jleft, int jright, int kleft, int kright){
    if(jright < jleft){
        return;
    }
    int jmid = (jleft+jright)/2;
    int bestk = -1;
    dp[i][jmid] = 0;
    for(int k = kleft; k <=min(jmid-1,kright); k++){
        if((dp[i-1][k] + c[k+1][jmid]) > dp[i][jmid]){
            dp[i][jmid] = dp[i-1][k] + c[k+1][jmid];
            bestk = k;
        }
    }

    calculate(i, jleft, jmid-1, kleft, bestk);
    calculate(i, jmid+1, jright, bestk, kright);
}
int main(){
  _
  cin>>t;
  while(t--){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
      cin>>a[i];
    }
    cost();
    initialize();
    for(lli i=2;i<=m;i++){
      calculate(i,1,n,1,n);
    }
    cout<<dp[m][n]<<endl;
  }
}
