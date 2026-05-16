#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

const ll MOD = 1e9 + 7;
const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

void solve() {
    int n = 7;
    vt<int> arr(n);
    for (auto& a : arr) cin >> a;
    sort(arr.begin(), arr.end());
    int ans = 0;
    for (int i = 0; i < 6; ++i) {
        ans += -1 * arr[i];
    }
    cout << ans + arr[6] << "\n";
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