#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define vt vector
 
void solve() {
    int n;
    cin >> n;
    vt<int> a(n);
    for (auto& s:a) cin >> s;
    sort(a.begin(), a.end());
    int s = 0;
    for (auto& v : a) s += v;
    int target = s/2 + 1;
 
    int ans = 0;
    for (int i = a.size()-1; i > -1; --i) {
        if (target <= 0) break;
        ans += 1;
        target -= a[i];
    }
    cout << ans << "\n";
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