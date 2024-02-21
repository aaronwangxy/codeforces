#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    int n;
    cin >> n;
    vt<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vt<int> freq(n+1);
    for (int i = 0; i < n; ++i) {
        freq[a[i]] = i+1;
    }
    for (int i = 1; i < n+1; ++i) {
        cout << freq[i] << " ";
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