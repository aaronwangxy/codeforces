#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    int n,m,d;
    cin >> n >> m >> d;
    vt<vt<int>> a(n, vt<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    int target = a[0][0] % d;
    bool valid = true;
    vt<int> sorted;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            sorted.push_back(a[i][j]);
            if (a[i][j] % d != target) {
                // invalid
                valid = false;
            }
        }
    }
    sort(sorted.begin(), sorted.end());
    if (!valid) cout << "-1" << endl;
    else {
        int ans = 0;
        int mid = sorted[(sorted.size()-1)/2];
        for (auto& v : sorted) {
            ans += abs((v-mid)/d);
        }
        cout << ans << endl;
    }
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