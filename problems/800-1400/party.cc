#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    int n;
    cin >> n;
    vt<int> p(n);
    for (auto& v:p) {
        cin >> v;
        v -= 1;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int curr = 0;
        int j = i;
        while (j != -2) {
            j = p[j];
            curr += 1;
        }
        ans = max(ans,curr);
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