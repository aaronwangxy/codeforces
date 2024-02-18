#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int retval = 0;
    for (int i = 0; i < n; ++i) {
        char a,b,c;
        cin >> a >> b >> c;
        if (a + b + c >= 2 + 48*3) {
            retval += 1;
        }
    } 
    cout << retval << endl;
}