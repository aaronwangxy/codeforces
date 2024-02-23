#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    string s;
    cin >> s;
    int cnt = 0;
    for (auto&c : s) {
        if (cnt == 0 && c == 'h') 
            cnt += 1;
        if (cnt == 1 && c == 'e')
            cnt += 1;
        if ((cnt == 2 || cnt == 3) && c == 'l')
            cnt += 1;
        if (cnt == 4 && c == 'o')
            cnt += 1;
    }
    if (cnt == 5) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
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