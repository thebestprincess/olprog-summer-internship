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
        int n, c, d;
        cin >> n >> c >> d;
        
        ll nn = n * n;
        vector<ll> b(nn);
        for (int i = 0; i < nn; ++i) cin >> b[i];
        sort(b.begin(), b.end());

        int a00 = b[0];
        
        vector<ll> matrix(nn);
        int cnt = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                matrix[cnt++] = a00 + i * c + j * d;
            }
        }
        sort(matrix.begin(), matrix.end());

        if (matrix == b) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
