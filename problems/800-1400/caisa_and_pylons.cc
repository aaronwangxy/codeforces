#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    int n;
    cin >> n;
    vt<int> h(n);
    for (auto& v : h) cin >> v;
    int energy = 0;
    int coins = 0;
    int curr = 0;
    for (int i = 0; i < n; ++i) {
        if (energy + curr < h[i]) {
            coins += h[i] - curr - energy;
            curr = h[i];
            energy = 0;
        } else {
            energy += curr - h[i];
            curr = h[i];
        }
    }
    cout << coins << endl;
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