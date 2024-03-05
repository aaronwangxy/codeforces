#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    int n;
    cin >> n;
    vt<vt<int>> a(n, vt<int> (2));
    for (auto& v: a) cin >> v[0] >> v[1];
    sort(a.begin(), a.end());
    int ans = 0;
    for (int i = 1; i < a.size(); ++i) {
        if (a[i][1] < a[i-1][1]) {
            ans = 1;
            break;
        }
    }
    if (ans) 
        cout << "Happy Alex\n";
    else
        cout << "Poor Alex\n";
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