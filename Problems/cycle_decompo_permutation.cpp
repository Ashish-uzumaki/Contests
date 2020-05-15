    for(int i=1;i<=n;i++) scanf("%d",&P[i]);
 
    int cycle=0;
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
 
        cycle++;
        int now=i;
        while(!vis[now]) {vis[now]=1; now=P[now];}
    }
    bool Parity=(n-cycle)&1;