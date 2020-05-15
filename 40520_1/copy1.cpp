#include <bits/stdc++.h>
using namespace std;
#define N 100009
#define INF 100000000007
#define MOD 1000000007
typedef long long int lli;
#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define pf1(x) printf("%d ",x);
#define pf2(x,y) printf("%d %d\n",x,y);
#define pf3(x,y,z) printf("%d %d %d\n",x,y,z);
#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
int a[N+1],b[N];
vector<pair<int,int> > v;
bool p[N+1];
void prime(){
    int i,j;
    for(i=2; i<N; i++){
        if(p[i])continue;
        j=2*i;
        while(j<N){
            p[j]=true;
            j+=i;
        }
    }
}
int main(){
  int n,x,i,j;
  sd(n);
  for(i=1; i<=n; i++){
      sd(x);
      b[i]=x;
      a[x]=i;
  }
  prime();
  int k,y,temp,j1,j2;
  for(i=1; i<n; i++){
      if(a[i]!=i){
          j1=i;
          j2=a[i];
          k=j2-j1+1;
        while(j2>j1){
            while(p[k]==true){
            k--;
            }
            swap(b[j2],b[j2-k+1]);
            a[b[j2]]=j2;;
            a[b[j2-k+1]]=j2-k+1;
            v.pb(mp(j2-k+1,j2));
            j2=j2-k+1;
            k=j2-j1+1;
        }
      }
  }
  cout << v.size() << endl;
  for(auto k: v){
      pf2(k.fi,k.se);
  }
}