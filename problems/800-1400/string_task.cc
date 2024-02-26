#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    string s;
    cin >> s;
    unordered_set<char> vowels ({'a','e','i','o','u', 'y'});
    for (auto& c : s) {
        if (c < 97 ) c += 32;
        if (vowels.find(c) != vowels.end()) continue;
        cout << "." << c;
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