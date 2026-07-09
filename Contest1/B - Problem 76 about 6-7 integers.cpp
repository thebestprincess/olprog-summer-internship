#include <iostream>
#include <vector>
#include <algorithm>
 
int main(int argc, char** argv)
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(NULL);
 
    int t;
    if (std::cin >> t)
    {
        while(t--)
        {
            std::vector<int> vec;
            for (int i = 0; i < 7; ++i)
            {
                int value;
                std::cin >> value;
                vec.push_back(value);
            }
 
            std::sort(vec.begin(), vec.end());
            
            int sum = 0;
            for (int i = 0; i < 7; ++i)
            {
                if (i != 6) sum += -vec[i];
                else sum += vec[i];
            }
            std::cout << sum << std::endl;
        }
    }
 
    return 0;
}