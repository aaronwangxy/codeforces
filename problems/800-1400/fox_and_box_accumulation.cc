#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    int n;
    cin >> n;
    vt<int> x(n);
    for (auto& a : x) cin >> a;

    sort(x.begin(), x.end());

    int ans = 0;
    int cnt = n;
    vt<int> visited(n,0);
    while (cnt) {
        ans += 1;
        vt<int> stack;
        for (int i=0; i<n; ++i) {
            if (!visited[i]) {
                if (x[i] >= stack.size()) {
                    stack.emplace_back(x[i]);
                    visited[i] = 1;
                    cnt -= 1;
                }
            }
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