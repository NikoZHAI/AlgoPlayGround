#include <iostream>
#include <vector>
#include <string>
#include <algorithm>    // std::find_if
#include <sstream>
#include <fstream>


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

void addTwoBin(short a[], short b[], int n)
{
    short *sum = new short[n+1](), s = 0; // Initialize sum array with all zeros

    for(int i = n; i > 0; i--)
    {
        s = sum[i] + a[i-1] + b[i-1];
        sum[i] = s % 2;
        if (s > 1) {
            sum[i-1] = 1;
        }
    }
    
    for(int i = 0; i < n+1; i++) {std::cout << sum[i];}
    std::cout << std::endl;
    delete[] sum;
}

int main()
{
    /* Introduction to Algorithms - 2.1-4
            ADD TWO BINARY NUMBERS
    */
    
    std::string line, filename;
    int n = 0;

    std::cin >> filename;
    std::ifstream myfile (filename);

    if (myfile.is_open()) {

        while(getline(myfile, line)){
            std::vector<short> a = stringToIntegerVector(line); // Read a
            
            getline(myfile, line); // Read b
            std::vector<short> b = stringToIntegerVector(line);

            n = a.size();
            
            if (n == b.size()) {
            addTwoBin(&a[0], &b[0], n);   
            } 
            else
            {   
                std::string err = "a and b are different in size, " + std::to_string(n)
                                + " and " + std::to_string(b.size());
                throw err;
            }
        } // endwhile

        myfile.close();
    } // endif
    
    return 0;
}

