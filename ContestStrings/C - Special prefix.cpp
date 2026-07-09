#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;
const ll P = 31;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    int n = s.size();

    int len = 0;
    ll h = 0, rh = 0, p = 1;

    for (int i = 0; i < n; ++i)
    {
        h = (h * P + s[i]) % MOD;
        rh = (rh + s[i] * p) % MOD;
        p = (p * P) % MOD;

        if (rh == h) len = i + 1;
    }

    std::cout << len << "\n";
    return 0;
}
