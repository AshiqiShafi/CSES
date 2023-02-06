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
 
vi adj[N];
bool vis[N];
int par[N];
int n, m;
 
void bfs(int u) {
  vis[u] = 1;
  queue<int> q;
  q.push(u);
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    if (v == n) return;
    for (auto x : adj[v]) {
      if (vis[x] == 0) {
        vis[x] = 1;
        par[x] = v;
        q.push(x);
      }
    }
  }
}
 
inline void solve () {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  bfs(1);
  if (vis[n] == 0) {
    cout << "IMPOSSIBLE" << '\n';
    return;
  }
  vector<int> ans;
  ans.pb(n);
  int u = n;
  while (u != 1) {
    u = par[u];
    ans.pb(u);
  }
  cout << ans.size() << '\n';
  reverse(ans.begin(), ans.end());
  for (auto x : ans) cout << x << ' ';
} 
 
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int T = 1; //cin >> T;
  while (T--) solve();
  return 0;
}
