#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void gen(int curr, set<int>& lucky) {
    if (curr > 100) {
        return;
    }

    lucky.insert(10*curr + 7);
    lucky.insert(10*curr + 4);

    gen(10*curr + 7, lucky);
    gen(10*curr + 4, lucky);
}

void solve() {
    int n;
    cin >> n;

    set<int> lucky;
    gen(0, lucky);

    bool valid = false;
    for (int v:lucky) {
        if (n%v == 0) {
            valid = true;
        }
    }
    if (valid) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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