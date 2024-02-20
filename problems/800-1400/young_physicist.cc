#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    int n;
    cin >> n;
    vt<int[3]> a(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> a[i][j];
        }
    }
    int x=0,y=0,z=0;
    for (int i = 0; i < n; ++i) {
        x += a[i][0];
        y += a[i][1];
        z += a[i][2];
    }
    if (!x && !y && !z) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
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