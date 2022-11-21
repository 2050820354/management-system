#include "utils.h"

std::vector<std::string> split(std::string str, char delim){
    std::stringstream st(str);
    std::string next;
    std::vector<std::string> res;
    while (std::getline(st, next, delim)){
        res.push_back(next);
    }
    return res;
}