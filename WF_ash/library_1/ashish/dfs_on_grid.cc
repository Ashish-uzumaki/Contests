int dx={-1,0,1,0};
int dy={0,1,0,-1};
int visit[1001][1001];
int n,m;

bool inside(int x,int y){
    if(x<0 or y<0 or x>n or y>m){
        return false;
    }
    return true;
}

void dfs(int x,int y){
    if(visit[x][y])
        return;
    visit[x][y]=1;
    for(int i=0;i<4;i++){
        if(inside(x+dx[i],y+dy[i])){
            dfs(x+dx[i],y+dy[i]);
        }
    }
}