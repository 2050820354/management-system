#ifndef TASK_SCHOOL_H
#define TASK_SCHOOL_H

#include "student.h"
#include "teacher.h"
#include "utils.h"
#include <vector>
#include <map>
#include <fstream>
#include <filesystem>
#include <iostream>

class School {
public:

    School();

    ~School();

    // run main app
    void run(std::string &data_base_path);

private:

    // loading data
    void load_data_base(std::string &data_base_path);

    void load_student_data(std::string &data_base_path);

    void load_teacher_data(std::string &data_base_path);

    void load_student_relations(std::string &data_base_path);

    void load_teacher_relations(std::string &data_base_path);

    // processing query
    void process_teacher_query(std::shared_ptr<Human> &human);

    void process_student_query(std::shared_ptr<Human> &human);

    std::vector<std::shared_ptr<Student>> students_vec;
    std::vector<std::shared_ptr<Teacher>> teachers_vec;
    std::map<std::pair<std::string, std::string>, std::shared_ptr<Teacher>> teachers;
    std::map<std::pair<std::string, std::string>, std::shared_ptr<Student>> students;
};


#endif //TASK_SCHOOL_H
