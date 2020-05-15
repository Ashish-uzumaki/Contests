#include <bits/stdc++.h>
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
 
using namespace std;
 
int getSqr(int x){
    int l = sqrt(x);
    for (int i = -2; i <= 2; ++i)
        if (l + i >= 0 && (l + i) * (l + i) == x)
            return l;
    return -1;
}
 
void solve(){
    int x;
    scanf("%d", &x);
    for (int n = 1; n == 1 || n * n - (n / 2) * (n / 2) <= x; ++n){
        int lk = n * n - x;
        if (lk < 0) continue;
        int sq = getSqr(lk);
        if (sq <= 0) continue;
       
        int k = n / sq;
        if (k > 0 && n * n - (n / k) * (n / k) == x){
            printf("%d %d\n", n, k);
            return;
        }
    }
   
    puts("-1");
}
 
int main() {
    int tc;
    scanf("%d", &tc);
    forn(i, tc)
        solve();
}