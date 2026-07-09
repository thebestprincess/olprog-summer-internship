#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

	vector<ll> dp(n+1, 0);
	vector<ll> pref(n+2, 0);
    dp[0] = 1;
    pref[1] = 1;
    for (ll i = 1; i <= n; ++i)
    {
        dp[i] = (pref[i] - pref[max(0LL, i - k)] + MOD) % MOD;
        pref[i + 1] = (pref[i] + dp[i]) % MOD;
    }

	cout << dp[n] << "\n";
	return 0;
}
