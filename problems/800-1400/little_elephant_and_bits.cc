#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    string a;
    cin >> a;

    bool found = false;
    for (int i = 0; i < a.size(); ++i) {
        if (!found && a[i] == '0') {
            found = true;
            continue;
        } else if (!found && i == a.size()-1) {
            continue;
        }
        cout << a[i];
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