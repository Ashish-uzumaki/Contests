int recur(int sum , int idx){
    if(sum >= n) return 0;
    if(idx >= n) return 1e18;
    int &res = dp[idx][sum];//this state also store the value for the dp;
    if(res != -1){
        return res;
    }
    res = min(recur(sum + v[idx].fi, idx + 1) + v[idx].se, recur(sum , idx + 1));
    return res;
}
//memoization beware this is not direct knapsack little modified see this link for further info
// https://codeforces.com/problemset/problem/19/B