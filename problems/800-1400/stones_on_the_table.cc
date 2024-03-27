#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int ans = 0;

    int l = 0;
    for (int r = 1; r < n; ++r) {
        char c = s[l];
        while (s[l] == s[r]) {
            ans += 1;
            r += 1;
        }
        l = r;
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