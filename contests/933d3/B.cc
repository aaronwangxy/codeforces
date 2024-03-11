#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    int n;
    cin >> n;
    vt<int> a(n);
    for (auto& v:a) cin >> v;

    int ans = true;
    for (int i = 1; i < n-1; ++i) {
        int req = a[i-1];
        if (req < 0) {
            ans = false;
            break;
        }
        a[i-1] -= req;
        a[i] -= 2*req;
        a[i+1] -= req;
        if (a[i] < 0 || a[i+1] < 0) {
            ans = false;
            break;
        }
    }
    if (ans && a[n-1] == 0 && a[n-2] == 0) cout << "YES\n";
    else cout << "NO\n";
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