#include "Sorting.h"

void Sorting::BubbleSort(long double* arr, int length){
    //Prints the current time at the start of the sorting process
    auto start = std::chrono::system_clock::now();
    std::time_t start_time = std::chrono::system_clock::to_time_t(start) - 25200;
    std::cout << "Started Bubble Sort at " << std::ctime(&start_time);

    //starts a timer
    auto timerStart = std::chrono::high_resolution_clock::now();

    /////IMPLEMENTATION/////

    for(int i = 0; i < length; i++){
        long double temp = 0;
        for(int j = 0; j < length-1; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    /////END IMPLEMENTATION/////

    //stops the timer and calculates its duration in mircoseconds
    auto timerStop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(timerStop - timerStart);

    //Prints the duration in seconds and microseconds
    std::cout << "Bubble s:  " << duration.count()/(long double)1000000 << std::endl;
    std::cout << "Bubble μ:  " << duration.count() << std::endl;
}

////////////

void Sorting::InsertionSort(long double* arr, int length){
     //Prints the current time at the start of the sorting process
    auto start = std::chrono::system_clock::now();
    std::time_t start_time = std::chrono::system_clock::to_time_t(start) - 25200;
    std::cout << "Started Insertion Sort at " << std::ctime(&start_time);

    //starts a timer
    auto timerStart = std::chrono::high_resolution_clock::now();

    /////IMPLEMENTATION/////

    for(int i = 0; i < length; i++){
        long double key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;

    }

    /////END IMPLEMENTATION/////

    //stops the timer and calculates its duration in mircoseconds
    auto timerStop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(timerStop - timerStart);

    //Prints the duration in seconds and microseconds
    std::cout << "Insertion s:  " << duration.count()/(long double)1000000 << std::endl;
    std::cout << "Insertion μ:  " << duration.count() << std::endl;
}

////////////

void Sorting::QuickSort(long double* arr, int length){
     //Prints the current time at the start of the sorting process
    auto start = std::chrono::system_clock::now();
    std::time_t start_time = std::chrono::system_clock::to_time_t(start) - 25200;
    std::cout << "Started Quick Sort at " << std::ctime(&start_time);

    auto timerStart = std::chrono::high_resolution_clock::now();

    /////IMPLEMENTATION/////

    QuickSortRec(arr, 0, length-1);

    /////END IMPLEMENTATION/////

    //stops the timer and calculates its duration in mircoseconds
    auto timerStop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(timerStop - timerStart);

    //Prints the duration in seconds and microseconds
    std::cout << "Quick s:  " << duration.count()/(long double)1000000 << std::endl;
    std::cout << "Quick μ:  " << duration.count() << std::endl;
}

void Sorting::QuickSortRec(long double* arr, int low, int high){
    if(low < high){
        int pi = Partition(arr, low, high);

        QuickSortRec(arr, low, pi-1);
        QuickSortRec(arr, pi+1, high);
    }
}

int Sorting::Partition(long double* arr, int low, int high){
    //choses the pivot as the highest element in the current subarray
    long double pivot = arr[high];
    int i = low - 1;

    //swaps elements that are supposed to be on opposite sides of the pivot
    for(int j = low; j <= high - 1; j++){
        if(arr[j] <= pivot){
            i++;
            long double temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    //puts the pivot in place
    long double temp = arr[high];
    arr[high] = arr[i+1];
    arr[i+1] = temp;

    //returns the index of the pivot
    return i+1;
}

////////////

int Sorting::index = 0;
void Sorting::TreeSort(long double* arr, int length){
     //Prints the current time at the start of the sorting process
    auto start = std::chrono::system_clock::now();
    std::time_t start_time = std::chrono::system_clock::to_time_t(start) - 25200;
    std::cout << "Started Tree Sort at " << std::ctime(&start_time);

    //starts a timer
    auto timerStart = std::chrono::high_resolution_clock::now();

    /////IMPLEMENTATION/////

    BST<long double> *b = new BST<long double>();

    //inserts all elements of the array into the tree
    for(int i = 0; i < length; i++){
        b->insert(arr[i]);
    }

    TreeNode<long double> *node = b->GetRoot();

    index = 0;
    Populate(arr, node);

    delete b;

    /////END IMPLEMENTATION/////

    //stops the timer and calculates its duration in mircoseconds
    auto timerStop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(timerStop - timerStart);

    //Prints the duration in seconds and microseconds
    std::cout << "Tree s:  " << duration.count()/(long double)1000000  << std::endl;
    std::cout << "Tree μ:  " << duration.count() << std::endl;
}

//In order traversal that populates the array
void Sorting::Populate(long double* arr, TreeNode<long double> *node){
    if(node == nullptr){
        return;
    }
    else{
        Populate(arr, node->left);
        arr[index++] = node->key;
        Populate(arr, node->right);
    }
}

////////////

/*
void Sorting::TimSort(long double* arr, int length){
     //Prints the current time at the start of the sorting process
    auto start = std::chrono::system_clock::now();
    std::time_t start_time = std::chrono::system_clock::to_time_t(start) - 25200;
    std::cout << "Started Tim Sort at " << std::ctime(&start_time);

    //starts a timer
    auto timerStart = std::chrono::high_resolution_clock::now();


    //IMPLEMENT HERE


    /*
    std::ofstream output("outputT.txt");

    for(int i = 0; i < length; i++){
        output << arr[i] << std::endl;
    }
    *

    auto timerStop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(timerStop - timerStart);

    std::cout << "Tim s:  " << duration.count()/(long double)1000000 << std::endl;
    std::cout << "Tim μ:  " << duration.count() << std::endl;
}
*/
