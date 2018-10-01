#include <BubbleSort.hpp>

void bubbleSort(std::vector<int>& a, int order = 1)
{
    int n = a.size();
    for(int i = 0; i < n; i++)
    {
        
        for(int j = n-1; j > i ; j--)
        {
            if (order*a.at(j) < order*a.at(j-1)) { std::swap(a[j], a[j-1]); }
        }
    }

    printVector(&a, n);
    std::cout << ';' << std::endl;
}

int main(void)
{
    /* Introduction to Algorithms - 2.3-9
                Bubble Sort
    */

    int order = 1;
    std::string filename, line;

    std::cout << "Input File: ";
    std::cin >> filename;
    std::cout << "Order (1 for Ascending, -1 for Desending): ";
    std::cin >> order;

    std::ifstream myfile (filename);
    if (myfile.is_open()) {
        while (getline(myfile, line)){
            std::vector<int> a = stringToIntegerVector(line);
            bubbleSort(a, order);
        }
    }

    return 0;
}
