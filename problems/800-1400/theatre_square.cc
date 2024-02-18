#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long n,m,a;
    cin >> n >> m >> a;
    long long side1 = (m+a-1)/a;
    long long side2 = (n+a-1)/a;
    cout << side1*side2 << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
}