#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    string s,t;
    cin >> s >> t;

    bool valid = s.size() == t.size();

    if (valid) {
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != t[t.size()-1-i]) {
                valid = false;
            }
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