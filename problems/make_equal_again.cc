#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; ++i) {
        int c;
        cin >> c;
        arr.emplace_back(c);
    }

    int start = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] == arr[0]) {
            start += 1;
        } else {
            break;
        }
    }
    int end = 0;
    for (int i = n-1; i >= 0; --i) {
        if (arr[i] == arr[n-1]) {
            end += 1;
        } else {
            break;
        }
    }
    if (start == n) {
        cout << 0 << endl;
    } else if (arr[0] == arr[n-1]) {
        cout << n-start-end << endl;
    } else {
        cout << n - max(start,end) << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}