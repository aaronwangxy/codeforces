#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    int n;
    cin >> n;
    vt<int> a(n);
    for (auto& v:a) cin >> v;

    bool easy = true;
    for (auto v:a) {
        if (v == 1) {
            easy = false;
        }
    }
    if (easy) {
        cout << "EASY\n";
    } else {
        cout << "HARD\n";
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