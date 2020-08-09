int a[N];
int visited[N];
ll ans;
vector<int> cycles;
ll dp[N];
int cyclecnt;

void dfs2(int u)
{
	cycles[cyclecnt]++;
	visited[u] = 3;
	if(visited[a[u]] == 3) return ;
	dfs2(a[u]);
}

void dfs(int u)
{
	visited[u] = 2;
	if(visited[a[u]] == 0)
	{
		dfs(a[u]);
	}
	else if(visited[a[u]] == 1)
	{
		visited[u] = 1;
		return ;
	}
	else
	{
		cycles.pb(0);
		dfs2(u);
		cyclecnt++;
	}
	visited[u] = 1;
}