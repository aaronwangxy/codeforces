#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    int n,m;
    cin >> n >> m;
    vector<ll> P;
    vector<ll> V;
    for (int i = 0; i < n; ++i) {
        ll c;
        cin >> c;
        P.emplace_back(c);
    }
    for (int i = 0; i < m; ++i) {
        ll c;
        cin >> c;
        V.emplace_back(c);
    }
    sort(P.begin(), P.end());
    sort(V.begin(), V.end());

    int l = P.size()-1;
    int r = V.size()-1;

    ll diff = 0;
    for (int i = 0; i < n; ++i) {
        if (abs(V[r] - P[i]) >= abs(V[l] - P[i])) {
            diff += abs(V[r] - P[i]);
            r -= 1;
            l -= 1;
        } else {
            diff += abs(V[l] - P[i]);
            l -= 1;
        }
    }
    cout << diff << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}