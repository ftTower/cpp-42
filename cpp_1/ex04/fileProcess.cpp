#include "fileProcess.hpp"

FileProcess::FileProcess(std::string filename, std::string s1, std::string s2) : filename(filename), s1(s1), s2(s2) {
        readFlux.open(filename.c_str(), std::ifstream::in);
        writeFlux.open((filename + ".replace").c_str(), std::ofstream::out);
}

FileProcess::FileProcess::~FileProcess() {
		readFlux.close();
		writeFlux.close();
}

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