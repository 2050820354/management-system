#include <iostream>
#include <fstream>
#include <string>
#include "school.h"
#include <filesystem>
#include "utils.h"

void reset_to_standart_input(std::streambuf * cinbuf, std::streambuf *coutbuf){
    std::cin.rdbuf(cinbuf);   //reset to standard input again
    std::cout.rdbuf(coutbuf); //reset to standard output again
}

bool check(std::string &data_base_path, std::string &input_file, std::string &output_file, std::string &result_file){
    School school;

    std::ifstream in(input_file);
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!

    std::ofstream out(output_file);
    std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
    std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

    std::ifstream res(result_file);

    // run app
    school.run(data_base_path);

    out.close();
    in.close();
    in.open(output_file);

    while (true){
        std::string line1, line2;
        bool ok1 = true, ok2 = true;
        if (!std::getline(res, line1)) ok1 = false;
        if (!std::getline(in, line2)) ok2 = false;
        if (ok1) line1 = split(line1, '\r')[0];
        if (ok2) line2 = split(line2, '\r')[0];
        if (ok1 != ok2){
            reset_to_standart_input(cinbuf, coutbuf);
            return false;
        }
        else if (ok1 == false) break;
        else if (line1 != line2){
            reset_to_standart_input(cinbuf, coutbuf);
            return false;
        }
    }

    reset_to_standart_input(cinbuf, coutbuf);
    return true;
}

int main(){

    std::string data_base_path = "../data_base";

    // run through all testes and test them
    for (auto const& dir_entry : std::filesystem::directory_iterator{"../testing"}) {
        auto splited = split(dir_entry.path(), '/');
        std::string test_dir = dir_entry.path();
        std::string input_file = test_dir + "/in.txt";
        std::string result_file = test_dir + "/res.txt";
        std::string output_file = test_dir + "/out.txt";
        if (!check(data_base_path, input_file, output_file, result_file)){
            std::cout << "Failed at test: " << splited.back() << '\n';
        }else {
            std::cout << "Test passed:    " << splited.back() << '\n';
        }
    }



    return 0;
}