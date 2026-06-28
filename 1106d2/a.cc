#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

const ll MOD = 1e9 + 7;
const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

void solve() {
    int n, c;
    cin >> n >> c;
    vt<int> aarr(n), barr(n);
    for (auto& a : aarr) cin >> a;
    for (auto& a : barr) cin >> a;

    int ans = 0;
    bool f = true;
    for (int i = 0; i < n; ++i) {
        if (barr[i] > aarr[i]) {
            f = false;
            break;
        }
        ans += aarr[i] - barr[i];
    }
    if (f) {
        cout << ans << "\n";
        return;
    }
    ans = c;
    sort(aarr.begin(), aarr.end());
    sort(barr.begin(), barr.end());
    for (int i = 0; i < n; ++i) {
        if (barr[i] > aarr[i]) {
            cout << "-1\n";
            return;
        }
        ans += aarr[i] - barr[i];
    }
    cout << ans << "\n";
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