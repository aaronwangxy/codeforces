#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    ll r,g,b;
    cin >> r >> g >> b;
    ll ans = 0;
    int mn = min({r,g,b});
    ans += mn;
    r -= mn;
    g -= mn;
    b -= mn;
    ans += r/3 + g/3 + b/3;
    r %= 3; g %= 3; b %= 3;
    if (r+g+b == 4 && mn) {
        ans += 1;
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