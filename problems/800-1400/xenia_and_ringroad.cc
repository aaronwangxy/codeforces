#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    int n,m;
    cin >> n >> m ;
    vt<int> a(m);
    for (auto& v : a) cin >> v;

    int currpos = 1;
    ll ans = 0;
    for (auto& v: a) {
        if (currpos <= v) {
            ans += v-currpos;
        } else {
            ans += v-currpos+n;
        }
        currpos = v;
    }
    cout << ans << endl;
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