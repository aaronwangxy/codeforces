#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    int n;
    cin >> n;
    vt<string> a(n);
    for (auto& s : a) cin >> s;
    unordered_map<char,char> m;
    char start = a[0][0];
    m[start] = '$';
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < n-1; ++j) {
            if (i < a[j].size() && i < a[j+1].size()) {
                if (a[j].substr(0, i) == a[j+1].substr(0,i)) {
                    if (start == a[j+1][i]) start = a[j][i];
                    char temp = m[a[j][i]];
                    m[a[j][i]] = a[j+1][i];
                    m[a[j+1][i]] = temp;
                }
            }
        }
    }

    vt<int> visited(26,0);
    char curr = start;
    while(curr != '$') {
        cout << curr;
        visited[curr] = 1;
        curr = m[curr];
    }
    cout << endl;
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