#include "fileProcess.hpp"

int main(int argc, char **argv)
{
    if (argc < 4)
        return (1);
    
    FileProcess fileProcess(argv[1], argv[2], argv[3]);
    fileProcess.replaceFileString();

    FileProcess fileProcess2("NOT EXISTING", argv[2], argv[3]);
    fileProcess2.replaceFileString();

    return (0);
}
