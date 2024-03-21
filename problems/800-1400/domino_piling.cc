#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    int m,n;
    cin >> m >> n;
    int ans = 0;
    ans += n*(m/2);
    if (m%2) {
        ans += n/2;
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