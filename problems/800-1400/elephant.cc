#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    double x;
    cin >> x;
    cout << ceil(x/5) << "\n";
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