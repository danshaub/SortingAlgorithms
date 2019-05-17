#include "FileReader.h"

std::ifstream FileReader::input;

//Returns the double array read from the file
long double* FileReader::GetDoubleArr(std::string fileName){
    using namespace std;

    //tests if the file is open already and closes it
    if(input.is_open()){
        input.close();
    }

    input.open(fileName);

    //if the file is invalid the program terminats
    if(!input.is_open()){
        cerr << "Invalid File Name: \"" + fileName + "\"" << endl;
        exit(EXIT_FAILURE);
    }

    string line = "";

    getline(input, line);

    int length;

    try{
        length = stoi(line);
    }
    catch(invalid_argument e){
        cerr << "Invalid first line of input file:  \"" + line + "\"" << endl;
        exit(EXIT_FAILURE);
    }
    catch(out_of_range e){
        cerr << "Invalid first line of input file:  \"" + line + "\"" << endl;
        exit(EXIT_FAILURE);
    }

    long double* arr = new long double[length];

    int index = 0;

    //for each line after the first, parses the data stored there into a double value and stores it in the array
    while(getline(input, line) && index != length){
        try{
            arr[index] = stod(line);
        }
        catch(invalid_argument e){
            cerr << "Invalid input at line " << index+2 << " of input file:  \"" + line + "\"" << endl;
            exit(EXIT_FAILURE);
        }
        catch(out_of_range e){
            cerr << "Invalid input at line " << index+2 << " of input file:  \"" + line + "\"" << endl;
            exit(EXIT_FAILURE);
        }

        index++;
    }

    //if there weren't enough elements in the file as specified from the first line, terminate
    if(index != length){
        cerr << "Invalid number of inputs: " << length << " elements expected, found " << index << endl;
        exit(EXIT_FAILURE);
    }

    return arr;
}

//Returns the number of elements stored in the double array
int FileReader::GetNumElements(std::string fileName){
    using namespace std;

    //tests if the file is open already and closes it
    if(input.is_open()){
        input.close();
    }
    
    input.open(fileName);

    //if the file is invalid the program terminats
    if(!input.is_open()){
        cerr << "Invalid File Name: \"" + fileName + "\"" << endl;
        exit(EXIT_FAILURE);
    }

    string line = "";

    getline(input, line);

    int length;

    try{
        length = stoi(line);
    }
    catch(invalid_argument e){
        cerr << "Invalid first line of input file:  \"" + line + "\"" << endl;
        exit(EXIT_FAILURE);
    }
    catch(out_of_range e){
        cerr << "Invalid first line of input file:  \"" + line + "\"" << endl;
        exit(EXIT_FAILURE);
    }
    
    return length;
}
