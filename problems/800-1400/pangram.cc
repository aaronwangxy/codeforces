#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    for (auto& c:s) {
        c = tolower(c);
    }
    set<char> mys (s.begin(), s.end());

    if (mys.size() == 26) {
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