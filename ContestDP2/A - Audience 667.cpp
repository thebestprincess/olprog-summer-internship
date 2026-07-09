#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<ll>> dp(n, vector<ll>(n, 0));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            cin >> dp[i][j];
        }
    }

    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            if (j == 0) dp[i][j] += dp[i - 1][j];
            else if(j == i) dp[i][j] += dp[i - 1][j - 1];
            else dp[i][j] += max(dp[i - 1][j - 1], dp[i - 1][j]);
        }
    }

    cout << *max_element(dp[n - 1].begin(), dp[n - 1].end()) << "\n";
    return 0;
}
