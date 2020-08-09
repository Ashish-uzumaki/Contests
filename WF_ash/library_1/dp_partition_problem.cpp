            for (int i = 0; i <= n; i++) {
                for (int j = 0; j <= m; j++) {
                    dp[i][j] = 1e9;
                }
            }
            dp[0][0] = 0;
            for(int i = 1; i <= n; i++) {
                for(int j = 0; j <= m and j<=i; j++) {
                    for (int k = 0; k < i; k++) {
                        if (j == 0) continue;
                        int cur_cost = dp[k][j - 1] + cost[k][i - 1];
                        dp[i][j] = min(dp[i][j], cur_cost);
                    }
                }
            }