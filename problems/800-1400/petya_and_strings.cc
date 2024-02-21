#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    string s1,s2;
    cin >> s1 >> s2;
    int state = 0;
    for (int i = 0; i < s1.size(); ++i) {
        if (tolower(s1[i]) == tolower(s2[i])) {
            continue;
        } else if (tolower(s1[i]) < tolower(s2[i])) {
            state = -1;
            break;
        } else {
            state = 1;
            break;
        }
    }
    cout << state << endl;
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