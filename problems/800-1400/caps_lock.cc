#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

bool rule(string& s) {
    for (int i = 1; i < s.size(); ++i) {
        if (islower(s[i])) {
            return false;
        }
    }
    return true;
}

void fix(string& s) {
    if (isupper(s[0])) {
        s[0] = tolower(s[0]);
    } else {
        s[0] = toupper(s[0]);
    }
    for (int i = 1; i < s.size(); ++i) {
        s[i] = tolower(s[i]);
    }
}

void solve() {
    string s;
    cin >> s;
    if (rule(s))
        fix(s);
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