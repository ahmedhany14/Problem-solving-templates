int n ,m;
int const maxn = 1000;
vc<vc<char>>grid;
bool vis_01[maxn][maxn] = {};
ll cost[maxn][maxn];

bool valid(int i ,int j){
  return i >= 0 and j >= 0 and i < n and j < m;
}

void bfs_01(int x1, int y1, int x2, int y2) {
  deque<pair<int,int>>dq;
  ::memset(vis_01 ,0 , sizeof vis_01);
  for (int i = 0; i < maxn; i++)for (int j = 0; j < maxn; j++)cost[i][j] =1e9;
  
  cost[x1][y1] = 0;

  dq.push_front({x1 ,y1});

  while (dq.size()){
    auto [r , c] = dq.front();
    dq.pop_front();
    // base case
    //      if(r == x2 and c == y2){
    //        cout << cost[r][c] << endl;
    //        return ;
    //      }

    if(vis_01[r][c]) continue ;

    vis_01[r][c] = 1;

    for(int i = 0 ;i < 8 ;i++){

      int nr = r + dx[i] , nc = c + dy[i];

      if(valid(nr ,nc) and !vis_01[nr][nc]){

        bool _01 = 0 ;

        int cur = cost[r][c];
        /*
         change of cost and _01
         */
        if(cost[nr][nc] > cur){
          cost[nr][nc] = cur ;
          if(_01) dq.push_back({nr , nc});
          else dq.push_front({nr , nc});
        }
      }
    }
  }
}
