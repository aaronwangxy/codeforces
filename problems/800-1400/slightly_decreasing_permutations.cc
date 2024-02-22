#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    int n,k;
    cin >> n >> k;

    vt<int> a(n);
    for (int i = 0; i < k+1; ++i) a[i] = k-i+1;
    
    for (int i = k+1; i < n; ++i) a[i] = i+1;

    for (auto& v : a) cout << v << " ";
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