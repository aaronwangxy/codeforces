#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    int n;
    cin >> n;
    vt<int> s(n);
    for (auto& v:s) cin >> v;

    sort(s.begin(), s.end());
    int ans = 0;
    int l = 0;
    int r = n-1;
    while (l <= r) {
        int curr = s[r];
        while (l < r && curr + s[l] <= 4) {
            curr += s[l];
            ++l;
        }
        --r;
        ++ans;
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