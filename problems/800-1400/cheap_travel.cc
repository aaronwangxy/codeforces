#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    int n,m,a,b;
    cin >> n >> m >> a >> b;

    int msf = 1e9;
    for (int i = 0; i <= n/m + 1; ++i) {
        msf = min(msf, i*b + max(0,a*(n-i*m)));
    }
    cout <<  msf << "\n";
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