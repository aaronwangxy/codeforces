#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    int k;
    string s;
    cin >> k >> s;
    vt<int> a(26, 0);
    for (auto& c : s)
        a[c-97] += 1;
    bool valid = true;
    string substr = "";
    for (int i = 0; i < 26; ++i) {
        if (a[i] % k) {
            valid = false;
            break;
        }
        for (int j = 0; j < a[i]/k; ++j)
            substr += (i+97);
    }
    if (valid) {
        for (int i = 0; i < k; ++i) {
            cout << substr;
        }
        cout << endl;
    }
    else {cout << "-1" << endl;}
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