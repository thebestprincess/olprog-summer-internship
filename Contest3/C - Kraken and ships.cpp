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
        ll n, k; 
        cin >> n >> k;

        vector<ll> durability(n);
        for (ll i = 0; i < n; ++i) cin >> durability[i];
    
        ll l = 0, r = n - 1;
        ll cnt = 0;

        while (k > 0 && l <= r)
        {
            ll ld = durability[l];
            ll rd = durability[r];

            if (l == r)
            {
                ll hits = min(durability[l], k);
                durability[l] -= hits;
                k -= hits;

                if (durability[l] == 0)
                {
                    ++l;
                    ++cnt;
                }
            }
            else
            {
                ll min_hits = min(ld, rd);
                
                if (k >= 2 * min_hits)
                {
                    durability[l] -= min_hits;
                    durability[r] -= min_hits;
                    k -= 2 * min_hits;

                    if (durability[l] == 0)
                    {
                        ++l;
                        ++cnt;
                    }
                    if (durability[r] == 0)
                    {
                        --r;
                        ++cnt;
                    }
                }
                else
                {
                    ll left_hits = (k + 1) / 2;
                    ll right_hits = k / 2;
                    
                    durability[l] -= left_hits;
                    durability[r] -= right_hits;
                    k = 0;
                    
                    if (durability[l] == 0)
                    {
                        ++l;
                        ++cnt;
                    }
                    if (durability[r] == 0) 
                    {
                        --r;
                        ++cnt;
                    }
                }
            }
        }

        cout << cnt << "\n";
    }

    return 0;
}
