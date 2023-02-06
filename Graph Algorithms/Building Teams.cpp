#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define ff first
#define ss second
#define pb push_back
#define pii pair<int, int>
#define vi vector<int>
#define vl vector<ll>
 
const int mod = 998244353;
const int N = 2e5 + 10;
 
vector<int> adj[N];
bool vis[N];
int color[N];
bool ok;
 
void dfs(int u, int c) {
  color[u] = c;
  for (auto v : adj[u]) {
    if (color[v] == 0) {
      dfs(v, (c == 1 ? 2 : 1));
    }
    else {
      ok &= (color[u] != color[v]);
    }
  }
}
 
inline void solve () {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  for (int i = 1; i <= n; i++) {
    if (color[i] == 0) {
      ok = 1;
      dfs(i, 1);
      if (!ok) break;
    }
  }
  if (!ok) {
    cout << "IMPOSSIBLE\n";
    return;
  }
  for (int i = 1; i <= n; i++) {
    cout << color[i] << ' ';
  }
  cout << '\n';
} 
 
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int T = 1; //cin >> T;
  while (T--) solve();
  return 0;
}
