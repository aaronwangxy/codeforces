#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    ll n;
    cin >> n;
    int ans = 0;
    while (n) {
        int remn = n%10;
        if (remn == 4 || remn == 7) {
            ans += 1;
        }
        n /= 10;
    }
    if (ans == 7 || ans == 4) {
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