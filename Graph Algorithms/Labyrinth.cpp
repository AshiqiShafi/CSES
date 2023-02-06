#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
const int mod = 1e9 + 7;
const int N = 2e5 + 123;
 
const int mx = 1001;
 
char grid[mx][mx];
bool vis[mx][mx];
int dir[mx][mx];
int sx, sy, ex, ey, n, m;
string str = "UDLR";
 
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
 
bool isValid (int i, int j) {
  if (i < 0 or i >= n or j < 0 or j >= m) return 0;
  if (vis[i][j]) return 0;
  return 1;
}
 
void bfs (int i, int j) {
  queue<pair<int, int>> q;
  q.push({i, j});
  vis[i][j] = 1;
  while (!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    if (x == ex && y == ey) break;
    for (int k = 0; k < 4; k++) {
      int newX = x + dx[k];
      int newY = y + dy[k];
      if (isValid(newX, newY) && grid[newX][newY] != '#') {
        q.push({newX, newY});
        vis[newX][newY] = 1;
        dir[newX][newY] = k;
      }
    }
  }
  if (vis[ex][ey]) {
    cout << "YES\n";
    string ans;
    while (1) {
      if (ex == sx && ey == sy) break;
      int p = dir[ex][ey];
      ans.push_back(str[p]);
      ex -= dx[p];
      ey -= dy[p];
    }
    cout << ans.size() << '\n';
    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
  }
  else cout << "NO\n";
}
 
inline void solve () {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> grid[i][j];
      if (grid[i][j] == 'A') {
        sx = i;
        sy = j;
      }
      if (grid[i][j] == 'B') {
        ex = i;
        ey = j;
      }
    }
  }
  bfs(sx, sy);
}
 
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int T = 1; //cin >> T;
  while (T--) solve();
  return 0;
}
