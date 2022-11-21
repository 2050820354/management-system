#include "student.h"

Student::Student() = default;

Student::Student(std::vector<std::string> &data) : Human(data[2], data[3], data[4], (unsigned int)std::stoul(data[5])) {
    set_login(data[0]);
    set_password(data[1]);
    set_name(data[2]);
    set_surname(data[3]);
    set_sex(data[4]);
    set_age((unsigned int)std::stoul(data[5]));
}

Student::~Student() = default;

// setter for login
void Student::set_login(std::string &log) {
    login = log;
}

// setter for password
void Student::set_password(std::string &pswd) {
    password = pswd;
}

// setter for id
void Student::set_id(int &i) {
    id = i;
}

// getter for id
int Student::get_id() {
    return id;
}

// method to add a teacher
void Student::add_teacher(int t) {
    teachers.push_back(t);
}

// getter for teachers variable
std::vector<int> Student::get_relations() {
    return teachers;
}