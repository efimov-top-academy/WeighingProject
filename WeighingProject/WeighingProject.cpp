#include <iostream>
#include <vector>

int main()
{
    int kettlebellMax{};
    std::vector<int> set;
    std::vector<int> left;
    std::vector<int> right;

    int weight;

    std::cout << "Input weight: ";
    std::cin >> weight;

    bool isFind{ false };
    int amount{};
    int numbers{};
    int number{};
    while(true)
    {
        set.clear();
        for (int i{}; i <= kettlebellMax; i++)
            set.push_back(pow(3, i));

        numbers = pow(2, set.size());
        number = 0;
        while (number < numbers)
        {
            isFind = false;
            amount = 0;
            int n = number;
            int i = set.size() - 1;
            while (n)
            {
                amount += (n % 2) * set[i];
                i--;
                n /= 2;
            }
            if (amount >= weight)
                isFind = true;
            if (isFind)
                break;
        }
        if (isFind)
            break;        
        kettlebellMax++;
    }
}
