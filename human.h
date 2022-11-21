#ifndef TASK_HUMAN_H
#define TASK_HUMAN_H

#include <string>
#include <vector>
//#include "teacher.h"
//#include "student.h"

//class Teacher;
//class Student;

class Human {
public:

    Human();

    Human(std::string name, std::string surname, std::string sex, int age);

    virtual ~Human();

    // setters
    void set_name(std::string &name);

    void set_surname(std::string &surname);

    void set_sex(std::string &sex);

    void set_age(int age);

    // getters
    std::string get_name();

    std::string get_surname();

    std::string get_sex();

    int get_age();

    virtual std::vector<int> get_relations() = 0;

    virtual int get_id() = 0;

protected:
    std::string name;
    std::string surname;
    std::string sex;
    int age;
};


#endif //TASK_HUMAN_H
