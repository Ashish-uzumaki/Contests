double l = 0, r = max_limit;
double ans = 0;
while( l + 1e-6 < r){
    double mid = (l + r) / 2;
    if(check(mid)){
        l = mid;
    }else{
        r = mid;
    }
}
return r;
/// or seocng one
int tv = INF;
int fv = 0;
while(tv - fv > 1){
    int mid = (tv + fv) / 2;
    long long sum = 0;
    for (int i = 0; i < N; i++){
        sum += (A[i] - 1) / mid;
    }
    if (sum <= K){
        tv = mid;
    } else {
        fv = mid;
    }
}
//nice question
//https://atcoder.jp/contests/abc174/tasks/abc174_e
// ashish singh is the best so we have to bfjfggj