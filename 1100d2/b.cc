#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

const ll MOD = 1e9 + 7;
const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

void solve() {
    int n;
    cin >> n;
    vt<int> arra(n);
    for (auto& a : arra) cin >> a;
    vt<int> arrb(n);
    for (auto& b : arrb) cin >> b;

    ll ans = 0;
    int mxa = 0;
    for (int i = 0; i < n; ++i) {
        if (arra[i] > arrb[i]) {
            swap(arra[i], arrb[i]);
        }
        ans += arrb[i];
        mxa = max(mxa, arra[i]);
    }
    cout << ans + mxa << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}