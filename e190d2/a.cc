#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

const ll MOD = 1e9 + 7;
const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

void solve() {
    ll n, a, b;
    cin >> n >> a >> b;

    if (3*a < b) {
        cout << n * a << "\n";
    } else {
        ll cost = 0;
        cost += b * (n / 3);
        n %= 3;
        if (b < a*n) {
            cost += b;
        } else {
            cost += a*n;
        }
        cout << cost << "\n";
    }
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