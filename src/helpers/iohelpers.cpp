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

std::vector<short> stringToIntegerVector(std::string input) {
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
