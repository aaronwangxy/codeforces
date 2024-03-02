#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    int n,k;
    cin >> n >> k;
    vt<vt<int>> p(n, vt<int>(2));
    for (auto& a : p) {
        cin >> a[0]; 
        cin >> a[1];
    }
    vt<int> scores(n);
    for (int i = 0; i < n; ++i) {
        scores[i] = 100*p[i][0] - p[i][1];
    }
    sort(scores.begin(), scores.end());
    int ans = 0;
    int target = scores[n-k];
    for (auto& s : scores) 
        if (s == target)
            ans += 1;
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