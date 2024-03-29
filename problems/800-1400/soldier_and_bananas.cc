#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    int k,n,w;
    cin >> k >> n >> w;
    cout << max(0, k*(w+1)*w/2-n) << "\n";
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