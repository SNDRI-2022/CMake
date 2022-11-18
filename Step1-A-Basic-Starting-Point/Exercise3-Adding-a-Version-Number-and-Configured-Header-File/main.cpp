#include <iostream>
#include <vector>

int main(int argv, char **argc)
{
    const std::vector<long long> test{123456789, 987654321, 1029384756};
    for (auto i = test.begin(); i != test.end(); i++)
        std::cout << *i << std::endl;

    return 0;
}