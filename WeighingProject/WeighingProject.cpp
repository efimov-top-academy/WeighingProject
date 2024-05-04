#include <iostream>
#include <vector>

int CampareBalance(int weight,
    std::vector<int> left,
    std::vector<int> right)
{
    int leftAmount{};
    int rightAmount{};

    for (int i{}; i < left.size(); i++)
        leftAmount += left[i] * pow(3, i);

    for (int i{}; i < right.size(); i++)
        rightAmount += right[i] * pow(3, i);
    rightAmount += weight;

    return leftAmount - rightAmount;
}

int KettlebellMax(int weight)
{
    int kettlebellMax{ -1 };

    int amount{};
    do
    {
        kettlebellMax++;
        amount = 0;
        for (int i{}; i <= kettlebellMax; i++)
            amount += pow(3, i);
    } while (amount < weight);

    return kettlebellMax;
}

void Weighing(int weight)
{
    std::vector<int> left;
    std::vector<int> right;

    bool isFind{ false };

    int kettlebellCount{ KettlebellMax(weight) + 1 };
    int combinations = pow(2, kettlebellCount);

    // weighing
    for (int r{}; r < combinations; r++)
    {
        int rcomb = r;
        right.clear();
        for (int i{}; i < kettlebellCount; i++)
        {
            right.push_back(rcomb % 2);
            rcomb /= 2;
        }

        /*std::cout << "right scales: \n";
        for (int i{}; i < right.size(); i++)
            std::cout << right[i] << " ";
        std::cout << "\n";*/

        for (int l{}; l < combinations; l++)
        {
            int lcomb = l;
            left.clear();

            for (int i{}; i < kettlebellCount; i++)
            {
                left.push_back((lcomb % 2) * !right[i]);
                lcomb /= 2;
            }

            /*std::cout << "\tleft scales: \n\t";
            for (int i{}; i < left.size(); i++)
                std::cout << left[i] << " ";
            std::cout << "\n";*/

            isFind = !CampareBalance(weight, left, right);
            if (isFind) break;
        }
        if (isFind) break;
    }

    std::cout << std::string(50, '*') << "\n";

    std::cout << "right scales: \n";
    for (int i{}; i < right.size(); i++)
        std::cout << right[i] * pow(3, i) << ", ";
    std::cout << "\n";

    std::cout << "left scales: \n";
    for (int i{}; i < left.size(); i++)
        std::cout << left[i] * pow(3, i) << ", ";
    std::cout << "\n";

    int leftAmount{};
    int rightAmount{};

    for (int i{}; i < left.size(); i++)
        leftAmount += left[i] * pow(3, i);

    for (int i{}; i < right.size(); i++)
        rightAmount += right[i] * pow(3, i);

    std::cout << "Left Weight = " << leftAmount << "\n";
    std::cout << "Right Weight = " << rightAmount << "\n";
    std::cout << "Weight = " << leftAmount - rightAmount << "\n";

    std::cout << std::string(50, '*') << "\n";
}

int main()
{

    /*int weight;

    std::cout << "Input weight: ";
    std::cin >> weight;*/

    for (int w{ 1000 }; w <= 1050; w++)
        Weighing(w);
}
