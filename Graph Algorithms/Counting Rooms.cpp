#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
 
char a[1001][1001];
bool vis[1001][1001];
int N, M;
 
bool isValid(int x, int y) {
  if (x < 1 || x > N || y < 1 || y > M) {
    return false;
  }
  if (vis[x][y] == true or a[x][y] == '#') return false;
  return true;
}
 
void dfs (int x, int y) {
  vis[x][y] = true;
  for (int i = 0; i < 4; i++) {
    if (isValid(x + dx[i], y + dy[i])) {
      dfs(x + dx[i], y + dy[i]);
    }
  }
}
 
int32_t main() {
  cin >> N >> M;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      cin >> a[i][j];
    }
  }
  int ans = 0;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      if (vis[i][j] == false && a[i][j] == '.') {
        dfs(i, j);
        ans++;
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
