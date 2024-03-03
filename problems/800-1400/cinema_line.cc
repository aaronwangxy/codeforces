#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    int n;
    cin >> n;
    vt<int> val(n);
    for (auto& v : val) cin >> v;
    int e25 = 0;
    int e50 = 0;
    bool valid = true;
    for (auto& v : val) {
        if (v == 25) {
            e25 += 1;
        } else if (v == 50) {
            e25 -= 1;
            e50 += 1;
            if (e25 < 0) {
                valid = false;
                break;
            }
        } else {
            if (e50 > 0 && e25 > 0) {
                e50 -= 1;
                e25 -= 1;
            } else {
                e25 -= 3;
            }
            if (e25 < 0) {
                valid = false;
                break;
            }
        }
    }
    if (!valid) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
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