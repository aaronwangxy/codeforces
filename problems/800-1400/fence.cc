#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    int n,k;
    cin >> n >> k;
    vt<int> j(n);
    for (auto& v : j) cin >> v;
    int currsum = 0;
    for (int i = 0; i < k; ++i) {
        currsum += j[i];
    }
    int minsum = currsum;
    int ans = 1;
    for (int r = k; r < n; ++r) {
        currsum = currsum + j[r] - j[r-k];
        if (currsum < minsum) {
            minsum = currsum;
            ans = r-k+2;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}