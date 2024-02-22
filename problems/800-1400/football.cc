#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    string s;
    cin >> s;
    bool dangerous = false;
    int cnt1 = 0;
    int cnt2 = 0;
    for (auto& c : s) {
        if (c == '1') {
            cnt1 += 1;
            cnt2 = 0;
        } else {
            cnt2 += 1;
            cnt1 = 0;
        }
        if (cnt1 == 7 || cnt2 == 7) {
            dangerous = true;
            break;
        }
    }
    if (dangerous) cout << "YES" << endl;
    else cout << "NO" << endl;
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