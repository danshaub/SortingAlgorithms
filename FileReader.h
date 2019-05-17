#ifndef FILE_READER_H
#define FILE_READER_H

#include <iostream>
#include <fstream>
#include <string>

class FileReader{
    public:
        //Returns the double array read from the file
        static long double* GetDoubleArr(std::string fileName);
        //Returns the number of elements stored in the double array
        static int GetNumElements(std::string fileName);
    private:
        static std::ifstream input;
};


#endif //FILE_READER_H