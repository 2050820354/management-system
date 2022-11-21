#ifndef TASK_TEACHER_H
#define TASK_TEACHER_H

#include "human.h"
#include <vector>
#include <memory>

class Teacher : public Human{
public:
    Teacher();

    Teacher(std::vector<std::string> &data);

    ~Teacher();

    // setters
    void set_login(std::string &login);

    void set_password(std::string &password);

    void set_id(int &i);

    void set_subject(std::string &sbj);

    // getters
    int get_id();

    std::string get_subject();

    std::vector<std::vector<int>> get_grades();

    std::vector<int> get_relations();

    // method for adding student
    void add_student(int st);

    // method for adding grade
    void add_grade(std::vector<int> &grade);

protected:
    std::vector<int> students;
    std::vector<std::vector<int>> grades;
    std::string subject;
    std::string login;
    std::string password;
    int id;
};


#endif //TASK_TEACHER_H
