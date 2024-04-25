#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    int s,n;
    cin >> s >> n;
    vt<vt<int>> x(n,vt<int>(2));

    for (auto& v: x) {
        for (auto& v2:v) {
            cin >> v2;
        }
    }

    sort(x.begin(), x.end());
    bool win = true;
    for (int i = 0; i < n; ++i) {
        if (s > x[i][0]) {
            s += x[i][1];
        } else {
            win = false;
        }
    }
    if (win) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
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