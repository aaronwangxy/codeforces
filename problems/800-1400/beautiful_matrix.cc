#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    vt<vt<int>> a(5, vt<int>(5));

    for (auto& r:a) {
        for (auto& c:r) 
            cin >> c;
    }

    pair<int,int> loc;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (a[i][j] == 1) {
                loc = make_pair(i,j);
            }
        }
    }
    cout << abs(loc.first - 2) + abs(loc.second - 2) << "\n";
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