#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    int n,p,q;
    cin >> n;
    
    cin >> p;
    vt<int> a(p);
    for (auto& v:a) cin >> v;
    cin >> q;
    vt<int> b(q);
    for (auto& v:b) cin >> v;

    set<int> lvls;
    for (int i = 1; i <= n; ++i) {
        lvls.insert(i);
    }
    for (auto v:a) {
        lvls.erase(v);
    }
    for (auto v:b) {
        lvls.erase(v);
    }
    if (lvls.size()) {
        cout << "Oh, my keyboard!\n";
    } else {
        cout << "I become the guy.\n";
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