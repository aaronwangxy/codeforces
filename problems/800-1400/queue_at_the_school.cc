#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    int n,t;
    cin >> n >> t;
    vt<char> q(n);
    for (auto& c:q) cin >> c;

    for (int i = 0; i < t; ++i) {
        for (int j = 0; j < n-1; ++j) {
            if (q[j] == 'B' && q[j+1] == 'G') {
                swap(q[j],q[j+1]);
                j++;
            }
        }
    }
    for (auto c:q) {
        cout << c;
    }
    cout << "\n";
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