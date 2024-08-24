
#include <iostream>
#include <fstream>

class FileProcess
{
public:
    std::string filename;
    const std::string s1;
    const std::string s2;

    std::ifstream readFlux;
    std::ofstream writeFlux;

    FileProcess(std::string filename, std::string s1, std::string s2) : filename(filename), s1(s1), s2(s2) {
        readFlux.open(filename.c_str(), std::ifstream::in);
        writeFlux.open((filename + ".replace").c_str(), std::ofstream::out);
    }
    void replaceFileString(void);
};

void FileProcess::replaceFileString()
{
    std::string buf;
    size_t pos_to_del = 0;

    while (getline(readFlux, buf))
    {
        while(buf.find(s1) != std::string::npos)
        {
            pos_to_del = buf.find(s1);
            buf.erase(pos_to_del, s1.length());
            buf.insert(pos_to_del, s2);
        }
        writeFlux << buf << std::endl;
    }
}

int main(int argc, char **argv)
{
    if (argc < 4)
        return (1);
    FileProcess fileProcess(argv[1], argv[2], argv[3]);
    fileProcess.replaceFileString();
    return (0);
}
