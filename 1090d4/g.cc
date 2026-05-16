#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

const ll MOD = 676767677;
const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

void solve() {
    int n, m;
    cin >> n >> m;
    vt<int> arr(n);
    for (auto& a : arr) cin >> a;

    for (int i = 0; i < n; ++i) {
        if (arr[i] != 0 && !(0 <= i-1 && arr[i-1] < arr[i] || i+1 < n && arr[i+1] < arr[i])) {
            cout << 0 << "\n";
            return;
        }
    }

    vt<vt<int>> sat_at_time(m);
    for (int i = 0; i < n; ++i) {
        sat_at_time[arr[i]].push_back(i);
    }

    vt<int> num_sat_at_time(m);
    num_sat_at_time[0] = sat_at_time[0].size();
    for (int i = 1; i < m; ++i) {
        num_sat_at_time[i] = num_sat_at_time[i-1] + sat_at_time[i].size();
    }

    ll ans = 1;
    for (int time = 1; time < m; ++time) {
        for (int i : sat_at_time[time]) {
            int options = num_sat_at_time[time-1];
            int mn = time;
            if (0 <= i-1 && arr[i-1] < mn) {
                mn = arr[i-1];
            }
            if (i+1 < n && arr[i+1] < mn) {
                mn = arr[i+1];
            }
            if (mn < time-1 && time-2 >= 0) {
                options -= num_sat_at_time[time-2];
            }
            ans = (ans * options) % MOD;
        }
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