#include <iostream>
#include <fstream>

class FileProcess
{
    public:
    FileProcess(std::string filename, std::string s1, std::string s2);
    ~FileProcess();
    std::string filename;
    const std::string s1;
    const std::string s2;

    std::ifstream readFlux;
    std::ofstream writeFlux;

    void replaceFileString(void);
};
