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

    int cnt[30] = {};
    int nonzero = 0;
    for (auto a : arr) {
        if (a) ++nonzero;
        int i = 0;
        while (a) {
            cnt[i] += a % 2;
            a /= 2;
            i += 1;
        }
    }

    if (nonzero <= 1) {
        cout << 0 << "\n";
        return;
    }

    for (int i = 29; i >= 0; --i) {
        if (cnt[i] % 2) {
            cout << cnt[i] << "\n";
            return;
        }
    }
    cout << 1 << "\n";
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