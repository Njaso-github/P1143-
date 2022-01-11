#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    map<int, char> m1;
    for (int i = 10; i <= 15; i++) {
        m1.insert({i, (char) 'A' + i - 10});
    }
    map<char, int> m2;
    for (int i = 10; i <= 15; i++) {
        m2.insert({(char) 'A' + i - 10, i});
    }
    int m;
    string n;
    cin >> m >> n;
    int t;
    cin >> t;
    int base10 = 0;
    for (int i = 0; i < (int) n.size(); i++) {
        int cnt = n.size() - 1 - i;
        int power = 1;
        while (cnt--) {
            power *= m;
        }
        if (isdigit(n[i])) {
            base10 += (int) (n[i] - '0') * power;
        } else {
            base10 += m2[n[i]] * power;
        }
    }
    vector<char> ans;
    while (base10 >= 1) {
        if (base10 % t <= 9) {
            ans.push_back((char) (base10 % t + '0'));
        } else {
            ans.push_back((char) m1[base10 % t]);
        }
        base10 /= t;
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < (int) ans.size(); i++) {
        cout << ans[i];
    }
    cout << '\n';
    return 0;
}