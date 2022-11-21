#include "human.h"

Human::Human() = default;

Human::Human(std::string name, std::string surname, std::string sex, int age) {
    set_name(name);
    set_surname(surname);
    set_sex(sex);
    set_age(age);
}

Human::~Human() = default;

// setter for name
void Human::set_name(std::string &nm) {
    name = nm;
}

// setter for surname
void Human::set_surname(std::string &sn) {
    surname = sn;
}

// setter for gender
void Human::set_sex(std::string &sx) {
    sex = sx;
}

// setter for age
void Human::set_age(int ag) {
    age = ag;
}

// getter for name
std::string Human::get_name() {
    return name;
}

// getter for surname
std::string Human::get_surname() {
    return surname;
}

// getter for sex
std::string Human::get_sex() {
    return sex;
}

// getter for age
int Human::get_age() {
    return age;
}