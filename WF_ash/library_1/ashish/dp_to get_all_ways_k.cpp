    int dfs(int x,int siz){
        freq[x]--;
        if(!siz){
            ans++;
        }
        for(auto p:g[x]){
            if(freq[p]>0){
                dfs(p,siz-1);
            }
        }
        freq[x]++;
    }