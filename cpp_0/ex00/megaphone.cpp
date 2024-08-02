#include <iostream>
#include <stdio.h>
#include <cctype>


int main(int argc, char **argv)
{
    if (argc > 1)
        for(int i = 1; argv[i]; i++)
        {
            for(int j = 0; argv[i][j]; j++)
               std::cout << (char)toupper(argv[i][j]);
            if (argv[i + 1])
                std::cout << " ";
        }
    else
        std::cout << "* LOUD AND UNBERABLE FEEDBACK NOISE *";
    std::cout << std::endl;
}
