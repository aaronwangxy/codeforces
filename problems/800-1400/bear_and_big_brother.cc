#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    int a,b;
    cin >> a >> b;
    int ans = 0;
    while (a<=b) {
        ans += 1;
        a *= 3;
        b *= 2;
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