#ifndef IOHELPER_HPP
#define IOHELPER_HPP

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>    // std::find_if
#include <sstream>
#include <fstream>

void trimRightTrailingSpaces(std::string &input);
void trimLeftTrailingSpaces(std::string &input);
std::vector<short> stringToIntegerVector(std::string input);

#endif