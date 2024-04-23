#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    int n;
    cin >> n;
    vt<int> x(n);
    for (auto& v:x) cin >> v;
    int q;
    cin >> q;
    vt<int> m(q);
    for (auto& v:m) cin >> v;

    sort(x.begin(), x.end());

    for (auto amt:m) {
        int l=0,r=n;
        while (l<r) {
            int mid = l + (r-l)/2;
            if (x[mid] > amt) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        cout << l << "\n";
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