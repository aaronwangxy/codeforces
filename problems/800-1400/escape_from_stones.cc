#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    string s;
    cin >> s;
    vt<int> a;
    vt<int> b;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'l') {
            a.emplace_back(i+1);
        } else {
            b.emplace_back(i+1);
        }
    }
    for (int i = 0; i < b.size(); ++i) cout << b[i] << "\n";
    for (int i = a.size()-1; i > -1; --i) cout << a[i] << "\n";
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