#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;


    int a = 0;
    int d = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'A') {
            a++;
        } else {
            d++;
        }
    }
    if (a < d) {
        cout << "Danik\n";
    } else if (a > d) {
        cout << "Anton\n";
    } else {
        cout << "Friendship\n";
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