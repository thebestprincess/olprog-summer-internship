#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    
    vector<ll> dp(N + 1, 0);
    for (int i = 2; i <= N; ++i)
    {
        ll min_prev = dp[i - 1];
        if (i % 2 == 0) min_prev = min(min_prev, dp[i / 2]);
        if (i % 3 == 0) min_prev = min(min_prev, dp[i / 3]);

        dp[i] = min_prev + i;
    }

    cout << dp[N] << "\n";
    return 0;
}
