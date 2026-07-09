#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll l, r;
    cin >> l >> r;

    vector<ll> dp(r + 1, 0);
    dp[1] = 1;
    for (ll i = 1; i <= r; ++i)
    {
        for (ll j = 2 * i; j <= r; j += i)
        {
            dp[j] = (dp[j] + dp[i]) % MOD;
        }
    }

    ll result = 0;
    for (ll i = l; i <= r; ++i)
    {
        result = (result + dp[i]) % MOD;
    }
    std::cout << result << "\n";
    return 0;
}
