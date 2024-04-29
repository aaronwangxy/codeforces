#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    int n,t;
    cin >> n >> t;
    vt<int> a(n-1);
    for (auto& v:a) cin >> v;
    int curr = 0;
    while (curr < a.size() && curr+1 != t) {
        curr += a[curr];
    }
    if (curr+1 == t) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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