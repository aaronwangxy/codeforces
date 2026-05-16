#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

const ll MOD = 1e9 + 7;
const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

void solve() {
    int n;
    cin >> n;
    vt<int> arr(n);
    for (auto& a : arr) cin >> a;

    int freq[3] = {};
    for (auto a : arr) freq[a]++;

    ll ans = freq[0];
    int common = min(freq[1], freq[2]);
    ans += common;
    freq[1] -= common;
    freq[2] -= common;
    ans += freq[1] / 3;
    ans += freq[2] / 3;
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