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
 
ll t[4 * N], a[N];
 
void build(int id, int b, int e) {
  if (b == e) {
    t[id] = a[b];
    return;
  }
  int mid = (b + e) >> 1;
  build(id * 2, b, mid);
  build(id * 2 + 1, mid + 1, e);
  t[id] = t[id * 2] + t[id * 2 + 1];
}
void update(int id, int b, int e, int idx, int val) {
  if (b > idx or e < idx) return;
  if (b == idx && e == idx) {
    t[id] = val;
    return;
  }
  int mid = (b + e) >> 1;
  update(id * 2, b, mid, idx, val);
  update(id * 2 + 1, mid + 1, e, idx, val);
  t[id] = t[id * 2] + t[id * 2 + 1];
}
ll query(int id, int b, int e, int i, int j) {
  if (b > j or e < i) return 0;
  if (b >= i && e <= j) return t[id];
  int mid = (b + e) >> 1;
  ll L = query(id * 2, b, mid, i, j);
  ll R = query(id * 2 + 1, mid + 1, e, i, j);
  return (L + R);
}
 
inline void solve () {
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  build(1, 1, n);
  while (q--) {
    int typ;
    cin >> typ;
    if (typ == 1) {
      int k, u;
      cin >> k >> u;
      update(1, 1, n, k, u);
    }
    else {
      int a, b;
      cin >> a >> b;
      cout << query(1, 1, n, a, b) << '\n';
    }
  }
} 
 
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int T = 1; //cin >> T;
  while (T--) solve();
  return 0;
}
