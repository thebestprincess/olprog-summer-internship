#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll P = 31;
const ll MOD = 1e9 + 7;
const ll N = 2 * 1e6;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    int n = s.size();

    vector<ll> p(n + 1, 1);
    vector<ll> h(n + 1, 0);
    for (ll i = 0; i < n; ++i)
    {
        p[i + 1] = (p[i] * P ) % MOD;
        h[i + 1] = (h[i] * P + s[i]) % MOD;
    }

    auto get_hash = [&](ll l, ll r)
    {
        ll hash = (h[r + 1] - h[l] * p[r - l + 1]) % MOD;
        if (hash < 0) hash += MOD;
        return hash;
    };

    for (ll len = 1; len <= n; ++len)
    {
        if (n % len == 0)
        {
            ll expected_hash = get_hash(0, len - 1);

            bool ok = true;
            for (ll i = len; i < n; i += len)
            {
                ll current_hash = get_hash(i, i + len - 1);
                if (current_hash != expected_hash)
                {
                    ok = false;
                    break;
                }
            }

            if (ok)
            {
                std::cout << len << "\n";
                return 0;
            }
        }
    }

    return 0;
}