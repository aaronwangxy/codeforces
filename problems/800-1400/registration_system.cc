#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    int n;
    cin >> n;

    map<string, int> cnt;

    while (n--) {
        string nme;
        cin >> nme;
        if (cnt.find(nme) == cnt.end()) {
            cout << "OK\n";
            cnt[nme] = 0;
        } else {
            cnt[nme]++;
            cout << nme << cnt[nme] << "\n";
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