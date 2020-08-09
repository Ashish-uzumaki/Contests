vector<int> topological_sort(int n) {
  queue<int> q;
  vector<int> indeg(n, 0);
  for (int i = 1; i <= n; i++) {
    for (auto p : g[i]) {
      indeg[p]++;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (indeg[i] == 0) {
      q.push(i);
    }
  }
  vector<int> T;
  int ans = 0;
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    T.push_back(x);
    for (auto y : g[x]) {
      indeg[y]--;
      if (indeg[y] == 0) {
        q.push(y);
      }
    }
  }
  // check indegrees for cycle detection even if one ofo the inedgree has more
  // than equal to 1 the cycle is present in the graph
  return T;
}
