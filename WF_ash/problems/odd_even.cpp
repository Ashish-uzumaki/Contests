class Solution {
    
    map<int, int> mp;
    bool odd(int val, vector<vector<bool>> &dp) {
        auto it = mp.lower_bound(val);
        if(it == mp.end())return false;
        return dp[it->second][1];
    }
    bool even(int val, vector<vector<bool>> &dp) {
        auto it = mp.upper_bound(val);
        if(it == mp.begin())return false;
        return dp[prev(it)->second][0];
    }
public:
    int oddEvenJumps(vector<int>& A) {
        int n = A.size();
        vector<vector<bool>> dp(n, vector<bool>(2));
        dp[n-1][0] = dp[n-1][1] =  true;
        mp[A[n-1]] = n-1;
        int ans = 1;
        for(int i = n-2; i >= 0; i--) {
            dp[i][0] = odd(A[i], dp);
            dp[i][1] = even(A[i], dp);
            ans += dp[i][0];
            mp[A[i]] = i;
        }
        return ans;
    }
};