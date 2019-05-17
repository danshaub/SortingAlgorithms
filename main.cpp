#include "FileReader.h"
#include "Sorting.h"
#include <iostream>
#include <random>

void Randomize(int num, long double*& arr, int& length);

int main(int argc, char **argv){
    if(argc != 2){
        std::cerr << "Invalid number of arguments" << std::endl;
        std::cerr << "Correct usage: ./assignment6.exe [file path]" << std::endl;
        std::cerr << "Correct usage: ./assignment6.exe [number of randomly generated elements]" << std::endl;   
        exit(EXIT_FAILURE);     
    }

    long double* arr;
    int length;

    std::ifstream inputTest(argv[1]);
    if(inputTest.is_open()){
        std::cout << "Reading from file..." << std::endl;
        arr = FileReader::GetDoubleArr(argv[1]);
        length = FileReader::GetNumElements(argv[1]);
    }
    else{
        try{
            int numRand = std::stoi(argv[1]);
            if(numRand <= 0){
                throw 0;
            }
            std::cout << "Randomly generating..." << std::endl;
            Randomize(numRand, arr, length);
            std::cout << std::endl;

        }
        catch(int e){
            std::cerr << "Invalid number of random elements. Must be positive and non zero" << std::endl;
            exit(EXIT_FAILURE);
        }
        catch(std::invalid_argument e){
            std::cerr << "Invalid file name" << std::endl;
            exit(EXIT_FAILURE);
        }
        catch(std::out_of_range e){
            std::cerr << "Invalid number of random elements. Must be less than or equal to the max integer value" << std::endl;
            exit(EXIT_FAILURE);
        }
    }

    

    long double* arrB = new long double[length];
    long double* arrI = new long double[length];
    long double* arrQ = new long double[length];
    long double* arrT = new long double[length];

    for(int i = 0; i < length; i++){
        arrB[i] = arr[i];
        arrI[i] = arr[i];
        arrQ[i] = arr[i];
        arrT[i] = arr[i];
    }

    Sorting::QuickSort(arrB, length);

    std::cout << std::endl;

    Sorting::TreeSort(arrQ, length);

    std::cout << std::endl;
    
    Sorting::InsertionSort(arrI, length);

    std::cout << std::endl;
    
    Sorting::BubbleSort(arrT, length);

    

    return 0;
}

void Randomize(int num, long double*& arr, int& length){
    auto start = std::chrono::system_clock::now();
    std::time_t start_time = std::chrono::system_clock::to_time_t(start);
    //std::cout << "Started generation at " << std::ctime(&start_time);

    auto timerStart = std::chrono::high_resolution_clock::now();
    
    length = num;
    arr = new long double[length];

    srand(time(0));
    
    for(int i = 0; i < length; i++){
        arr[i] = ((rand()/10000) + (rand()/(long double)RAND_MAX)) * (((rand()%2)*2)-1);
    }

    auto timerStop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(timerStop - timerStart);

    auto end = std::chrono::system_clock::now();
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    //std::cout << "Finished Generation at " << std::ctime(&end_time);
    //std::cout << "(Generating took " << duration.count()/(long double)1000000 << " seconds)" << std::endl;
    //std::cout << "(Generating took " << duration.count() << " microseconds)" << std::endl;
}