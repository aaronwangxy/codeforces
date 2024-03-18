#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    int n;
    cin >> n;
    vt<string> s(n);
    for (auto& v : s) cin >> v;

    int val = 0;
    for (auto& v : s) {
        for (auto& c : v) {
            if (c == '-') {
                val -= 1;
                break;
            } else if (c == '+') {
                val += 1;
                break;
            }
        }
    }
    cout << val << "\n";
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