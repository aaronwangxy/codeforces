#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    int n,m;
    cin >> n;
    vt<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    cin >> m;
    vt<int> b(m);
    for (int i = 0; i < m; ++i) cin >> b[i];

    vt<int> posn(n);
    for (int i = 0; i < n; ++i) {
        posn[a[i]-1] = i;
    }

    ll vasya = 0;
    ll petya = 0;
    for (auto& v : b) {
        vasya += posn[v-1]+1;
        petya += n-posn[v-1];
    }
    cout << vasya << " " << petya << endl;
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