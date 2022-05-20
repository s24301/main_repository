#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

auto main(int argc, char* argv[]) -> int
{
    if (argc == 0) return 1;

    auto value = std::string{argv[1]};
    auto k = std::stoi(value);

    for (int n=1;n<=k;n++)
    {
        std::cout<<n<<" ";
        if (n%3==0) std::cout<<"Fizz";
        if (n%5==0) std::cout<<"Buzz";
        std::cout<<"\n";
    }

    return 0;
}
