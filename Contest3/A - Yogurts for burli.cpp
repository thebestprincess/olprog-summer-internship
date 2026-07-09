#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n, a, b;
        cin >> n >> a >> b;

        vector<ll> dp(n + 1, 0);
        dp[1] = a;
        for (int i = 2; i <= n; ++i)
        {
            dp[i] = dp[i-1] + a;
            if (i % 2 == 0)
            {
                dp[i] = min(dp[i], min(dp[i - 2] + 2 * a, dp[i - 2] + b));
            }
        }

        cout << dp[n] << "\n";
    }

    return 0;
}