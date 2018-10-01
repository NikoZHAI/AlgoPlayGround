#include <iohelpers.hpp>

void trimRightTrailingSpaces(std::string &input) {
    input.erase(std::find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

void trimLeftTrailingSpaces(std::string &input) {
    input.erase(input.begin(), std::find_if(input.begin(), input.end(), [](int ch) { // TODO
        return !isspace(ch);
    }));
}

std::vector<short> stringToShortVector(std::string input) {
    std::vector<short> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    //input = input.substr(1, input.length() - 2);
    std::stringstream ss;
    ss.str(input);
    std::string item;
    char delim = ' ';
    while (std::getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

std::vector<int> stringToIntegerVector(std::string input) {
    std::vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    //input = input.substr(1, input.length() - 2);
    std::stringstream ss;
    ss.str(input);
    std::string item;
    char delim = ' ';
    while (std::getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

void printArray(const int *arr, int length)
{
    // if user passed in a null pointer for array, bail out early!
    if (!arr)
        return;
  
    for (int i{ 0 }; i < length; ++i)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
    arr = nullptr;
}

void printVector(const std::vector<int>* arr, int length)
{
    // if user passed in a null pointer for array, bail out early!
    if (!arr)
        return;
  
    for (int i{ 0 }; i < length; ++i)
    {
        std::cout << arr->at(i) << ' ';
    }
    std::cout << std::endl;
    arr = nullptr;
}