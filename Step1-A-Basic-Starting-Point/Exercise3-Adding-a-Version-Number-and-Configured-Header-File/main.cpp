#include <iostream>
#include "exercise3.h"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        // report version
        std::cout << argv[0] << " Version " << Exercise3_VERSION_MAJOR << "."
                  << Exercise3_VERSION_MINOR << std::endl;
        std::cout << "Usage: " << argv[0] << " number" << std::endl;
        return 1;
    }

    return 0;
}