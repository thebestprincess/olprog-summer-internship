#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    
    while(t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> v(k);
        for (int i = 0; i < k; ++i) cin >> v[i];

        int mx = v[0];
        ll actions = 0;
        for (int i = 1; i < k; ++i)
        {
            int cur = v[i];
            if (mx < cur && cur != 1)
            {
                actions += 2LL * mx - 1;
                mx = cur;
            }
            else
            {
                if (cur == 1) ++actions;
                else actions += 2LL * cur - 1;
            }
        }

        cout << actions << "\n";
    }

    return 0;
}
