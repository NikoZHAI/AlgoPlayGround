#ifndef IOHELPER_HPP
#define IOHELPER_HPP

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>    // std::find_if; std::swap
#include <sstream>
#include <fstream>

void trimRightTrailingSpaces(std::string &input);
void trimLeftTrailingSpaces(std::string &input);
std::vector<short> stringToShortVector(std::string input);
std::vector<int> stringToIntegerVector(std::string input);
void printArray(const int* arr, int length);
void printVector(const std::vector<int>* arr, int length);

#endif