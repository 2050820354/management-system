#include "teacher.h"

Teacher::Teacher() = default;

Teacher::Teacher(std::vector<std::string> &data) : Human(data[2], data[3], data[4], (unsigned int)std::stoul(data[5])){
    set_login(data[0]);
    set_password(data[1]);
    set_name(data[2]);
    set_surname(data[3]);
    set_sex(data[4]);
    set_age((unsigned int)std::stoul(data[5]));
}

Teacher::~Teacher() = default;

// setter for login
void Teacher::set_login(std::string &log) {
    login = log;
}

// setter for password
void Teacher::set_password(std::string &pswd) {
    password = pswd;
}

// setter for id
void Teacher::set_id(int &i) {
    id = i;
}

// getter for id
int Teacher::get_id() {
    return id;
}

// method to add a student
void Teacher::add_student(int st) {
    students.push_back(st);
}

// setter for subject
void Teacher::set_subject(std::string &sbj) {
    subject = sbj;
}

// method to add a grade
void Teacher::add_grade(std::vector<int> &grade) {
    grades.push_back(grade);
}

// getter for subject
std::string Teacher::get_subject() {
    return subject;
}

// getter for grades
std::vector<std::vector<int>> Teacher::get_grades() {
    return grades;
}

// getter for students
std::vector<int> Teacher::get_relations() {
    return students;
}