int color[N];
int flag=0;
void dfs(int v){
  color[v] = 1;
  for(int w : g[v]){
    if(color[w] == 1){
      flag=1;
    }
    if(color[w] == 0) dfs(w, v);
  }
  color[v] = 2;
}