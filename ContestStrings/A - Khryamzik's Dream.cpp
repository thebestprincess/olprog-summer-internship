#include <vector>
#include <iostream>
 
int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
 
    std::string name, dream;
    if (!(std::cin >> name >> dream)) return -1;
 
    if (name.size() != dream.size())
    {
        std::cout << "-1\n";
        return 0;
    }
    
    int size = name.size();
    bool correct;
 
    std::vector<int> shift(size, 0);
 
    for (int i = 0; i < size; ++i)
    {
        correct = true;
 
        for (int j = 0; j < size; ++j)
        {
            if (dream[(i + j) % size] != name[j])
            {
                correct = false;
                break;
            }
            else
            {
                ++shift[i];
            }
        }
 
        if (shift[i] == size)
        {
            std::cout << i << "\n";
            break;
        }
 
        i += shift[i];
    }
    if (!correct)
    {
        std::cout << "-1\n";
    }
 
    return 0;
}