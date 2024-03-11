#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    int n,m,k,d;
    cin >> n >> m >> k >> d;
    vt<vt<int>> grid (n, vt<int>(m));
    for (auto& r:grid) {
        for (auto& c:r) {
            cin >> c;
        }
    }
    vt<ll> cost (n);

    // Optimize
    for (int r = 0; r < n; ++r) {
        vt<ll> dp (m,-1);
        dp[0] = 1;
        set<ll> s;
        for (int i = 1; i <= min(d+1,m-1); ++i) {
            dp[i] = grid[r][i] + 1 + dp[0];
            s.insert(dp[i]);
        }
        for (int i = d+2; i < m; ++i) {
            dp[i] = grid[r][i] + 1 + *s.begin();
            s.erase(dp[i-d-1]);
        }
        for (auto& v : dp) cout << v << " ";
        cost[r] = dp[m-1];
    }

    for (int i = 1; i < n; ++i) {
        cost[i] += cost[i-1];
    }
    ll msf = cost[k-1];
    for (int i = 1; i < n-k+1; ++i) {
        msf = min(msf, cost[i+k-1]-cost[i-1]);
    }
    cout << msf << "\n";
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}