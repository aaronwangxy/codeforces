#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    string s;
    cin >> s;
    int cnt = 0;
    for (auto c:s) {
        if (c < 97) {
            cnt += 1;
        }
    }
    if (cnt > s.size()-cnt) {
        for (auto& c:s) {
            c = toupper(c);
        }
    } else {
        for (auto& c : s) {
            c = tolower(c);
        }
    }
    cout << s << "\n";
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