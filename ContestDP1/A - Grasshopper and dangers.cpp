#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n;
    ll k;
    ll m;
    cin >> n >> k >> m;

    vector<bool> bad(n + 1, false);
    for (ll i = 0; i < m; ++i)
    {
        int point;
        cin >> point;
        bad[point] = true;
    } 

    vector<ll> dp(n + 1, 0);
    dp[0] = 1;
    ll pref = 1;

    for (ll i = 1; i <= n; ++i)
    {
        if (bad[i]) dp[i] = 0;
        else dp[i] = pref;

        pref = (pref + dp[i]) % MOD;

        if (i >= k) pref = (pref - dp[i - k] + MOD) % MOD;
    }

    cout << dp[n] << "\n";
    return 0;
}
