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
 
void dfs(int u) {
  vis[u] = 1;
  for (auto v : adj[u]) {
    if (!vis[v]) dfs(v);
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
  vector<int> ans;
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      dfs(i);
      ans.pb(i);
    }
  }
  cout << ans.size() - 1 << '\n';
  for (int i = 0; i < ans.size() - 1; i++) {
    cout << ans[i] << ' ' << ans[i + 1] << '\n'; 
  }
} 
 
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int T = 1; //cin >> T;
  while (T--) solve();
  return 0;
}
