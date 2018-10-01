#include <InsertionSort.hpp>

void insertionSort(std::vector<int> &a, int order = 1){
    int n = a.size(), key, j;

    for(int i = 1; i < n; i++)
    {
        key = a[i];
        j = i-1;

        while(j >= 0)
        {
            if (order*key < order*a[j]) {
                a[j+1] = a[j];
            } else {
                break;
            }
            j--;
        }
        a[j+1] = key;
    }
    
    printVector(&a, n);
    std::cout << ';' << std::endl;
}

int main(void)
{
    int order = 1;
    std::string filename, line;

    std::cout << "Input File: ";
    std::cin >> filename;
    std::cout << "Order (1 for Ascending, -1 for Desending): ";
    std::cin >> order;

    std::ifstream myfile (filename);
    if (myfile.is_open()){
        while(getline(myfile, line)){
            std::vector<int> vec = stringToIntegerVector(line);
            insertionSort(vec, order);
        } //endwhile
        myfile.close();
    } //endif

    return 0;
}
