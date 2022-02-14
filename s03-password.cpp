#include <iostream>
#include <string>
#include <algorithm>

auto main(int argc, char* argv[]) -> int
{
    if (argc == 0) return 1;

    auto password = std::string{argv[1]};
    auto p = std::string{};
    do
    {
        std::cout<<"password: ";
        std::getline(std::cin,p);        

    }while (p != password);


    return 0;

}
