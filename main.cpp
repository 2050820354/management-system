#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include "student.h"
#include "teacher.h"
#include <filesystem>
#include "school.h"

int main(){
    std::string data_base_path = "../data_base";

    School school;
    // run app
    school.run(data_base_path);

    return 0;
}
