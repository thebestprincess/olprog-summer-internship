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

    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<int> mask(n, 0);
    for (int i = n - k; i < n; ++i) mask[i] = 1;

    int max_xor = 0;
    do
    {
        int current_xor = 0;
        for (int i = 0; i < n; ++i)
        {
            if (mask[i]) current_xor ^= a[i];
        }
        max_xor = max(max_xor, current_xor);
    } while(next_permutation(mask.begin(), mask.end()));

    cout << max_xor << "\n";
    return 0;
}
