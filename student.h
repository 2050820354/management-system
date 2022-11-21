#ifndef TASK_STUDENT_H
#define TASK_STUDENT_H

#include "human.h"
#include <vector>
#include <memory>
#include <string>

class Student : public Human{
public:
    Student();

    Student(std::vector<std::string> &data);

    ~Student();

    // setters
    void set_login(std::string &login);

    void set_password(std::string &password);

    void set_id(int &i);

    // getters
    int get_id();

    std::vector<int> get_relations();

    // method for adding teacher
    void add_teacher(int t);

protected:
    std::vector<int> teachers;
    std::string login;
    std::string password;
    int id;
};


#endif //TASK_STUDENT_H
