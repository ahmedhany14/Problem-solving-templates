int n;
ll dp[305][305],cost[305][305];//Floyd-Warshall
void floydWarshall() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      dp[i][j] = oo;
      if (i == j)
        dp[i][j] = 0;
    }
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      for (int k = 1; k <= n; k++) {
        dp[i][j] = min(dp[i][j], cost[i][k] + cost[k][j]);
      }
}
