#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    ll n,k;
    cin >> n >> k;

    if (k <= (n+1)/2) {
        cout << 2*k-1 << "\n";
    } else {
        cout << 2*(k-(n+1)/2) << "\n";
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