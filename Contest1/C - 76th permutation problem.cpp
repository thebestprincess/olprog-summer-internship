#include <iostream>
 
 
int main(int argc, char** argv)
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
 
    int t;
    if (std::cin >> t)
    {
        while(t--)
        {
            int n;
            std::cin >> n;
 
            for (int i = 1; i <= n; i++)
            {
                std::cout << i << " " << n + 2 * i - 1 << " " << n + 2 * i;
                if (i == n) std::cout << std::endl;
                else std::cout << " ";
            }
        }
    }
}