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
 
int t[4 * N], a[N];
 
void build(int id, int b, int e) {
  if (b == e) {
    t[id] = a[b];
    return;
  }
  int mid = (b + e) >> 1;
  build(id * 2, b, mid);
  build(id * 2 + 1, mid + 1, e);
  t[id] = min(t[id * 2], t[id * 2 + 1]);
}
int query(int id, int b, int e, int i, int j) {
  if (b > j or e < i) return INT_MAX;
  if (b >= i && e <= j) return t[id];
  int mid = (b + e) >> 1;
  int L = query(id * 2, b, mid, i, j);
  int R = query(id * 2 + 1, mid + 1, e, i, j);
  return min(L, R);
}
 
inline void solve () {
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  build(1, 1, n);
  while (q--) {
    int a, b;
    cin >> a >> b;
    cout << query(1, 1, n, a, b) << '\n';
  }
} 
 
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int T = 1; //cin >> T;
  while (T--) solve();
  return 0;
}
