#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

const ll MOD = 1000000007;

void solve() {
    int n,m;
    cin >> n >> m;
    vt<string> names(n);
    for (auto& v:names) cin >> v;

    vt<int> unique(m,0);
    for (int i = 0; i < m; ++i) {
        vt<char> seen(26);
        for (int j = 0; j < n; ++j) {
            char curr = names[j][i];
            if (seen[curr-'A'] != 1) {
                seen[curr-'A'] = 1;
                unique[i] += 1;
            } 
        }
    }
    ll ans = 1;
    for (int v:unique) {
        ans = (ans*v)%MOD;
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