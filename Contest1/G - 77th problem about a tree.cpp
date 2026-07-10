#include <iostream>

int main(int argc, char** argv)
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int t;
    if (!(std::cin >> t)) return -1;

    while(t--)
    {
        int x, y;
        std::cin >> x >> y;

        if (x > y || (x == 0 && y % 2 == 0))
        {
            std::cout << "NO\n";
            continue;
        }
        else std::cout << "YES\n";
        
        int n = x + y;
        int edges = (n % 2 == 0) ? x - 1 : x;

        int vertex = 2;

        for (int i = 0; i < edges; ++i)
        {
            std::cout << 1 << " " << vertex << "\n";
            std::cout << vertex << " " << vertex + 1 << "\n";
            vertex += 2;
        }

        while (vertex <= n) std::cout << 1 << " " << vertex++ << "\n";
    }


    return 0;
}