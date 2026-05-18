#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

const ll MOD = 1e9 + 7;
const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

/*
Divisibility by 4: 2 digits divisible by 4
4, 12, 32
- need to remove all 4s
- need to remove all 12s and 32s (what's optimal?) 1221112
    - string is blocks of {13}{2}
    - find largest {2}{13} block n-that size
*/
void solve() {
    string s;
    cin >> s;
    int n = s.size();
    
    int msf = 0;
    vt<int> pre2(n);
    pre2[0] = int(s[0] == '2');
    vt<int> post13(n);
    post13[n-1] = int(s[n-1] == '1' || s[n-1] == '3');
    for (int i = 1; i < n; ++i) {
        pre2[i] = pre2[i-1];
        post13[n-1-i] = post13[n-1-i+1];
        if (s[i] == '2') {
            pre2[i] += 1;
        }
        if (s[n-1-i] == '1' || s[n-1-i] == '3') {
            post13[n-1-i] += 1;
        }
    }
    for (int i = 0; i < n; ++i) {
        msf = max(msf, pre2[i] + post13[i]);
    }

    cout << n - msf << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}