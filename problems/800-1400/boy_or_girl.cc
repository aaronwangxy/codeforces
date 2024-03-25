#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    string s;
    cin >> s;

    set<char> mys;
    for (char c : s) {
        mys.insert(c);
    }
    if (mys.size() % 2) {
        cout << "IGNORE HIM!\n";
    } else {
        cout << "CHAT WITH HER!\n";
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