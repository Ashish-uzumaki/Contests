    int ans = 0;
    int l = 1;
    int r = min(s1.size(), s2.size());
    while (l <= r) {
        int m = (l + r) / 2;
        if (isPossible(s1, s2, m)) {
            ans = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }