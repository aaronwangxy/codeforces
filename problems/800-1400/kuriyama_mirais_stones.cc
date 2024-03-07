#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    int n;
    cin >> n;
    vt<ll> v(n);
    for (auto& a:v) cin >> a;
    int m;
    cin >> m;
    vt<vt<int>> tlr(m,vt<int>(3));
    for (auto& a:tlr) {
        cin >> a[0] >> a[1] >> a[2];
        a[1] -= 1;
        a[2] -= 1;
    }

    vt<ll> vs = v;
    sort(vs.begin(), vs.end());

    for (int i = 1; i < n; ++i) {
        v[i] += v[i-1];
        vs[i] += vs[i-1];
    }

    for(auto& q:tlr) {
        if (q[0] == 1) {
            if (q[1]-1 < 0) {
                cout << v[q[2]] << "\n";
            } else {
                cout << v[q[2]]-v[q[1]-1] << "\n";
            }
            
        } else {
            if (q[1]-1 < 0) {
                cout << vs[q[2]] << "\n";
            } else {
                cout << vs[q[2]]-vs[q[1]-1] << "\n";
            }
        }
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