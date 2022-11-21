#include "school.h"

School::School() = default;

School::~School() = default;

// loading student data
void School::load_student_data(std::string &data_base_path) {
    // reading data
    std::string students_data_path = data_base_path + "/students.txt";
    std::ifstream student_file;
    student_file.open(students_data_path);
    std::string line;
    int idx = 1;
    while (std::getline(student_file, line)){
        // splitting line
        std::vector<std::string> splited = split(line, ' ');
        std::shared_ptr<Student> st = std::make_shared<Student>(splited);
        st->set_id(idx);
        students[{splited[0], splited[1]}] = st;
        students_vec.push_back(st);
        idx++;
    }
}

// loading teacher data
void School::load_teacher_data(std::string &data_base_path) {
    std::string teachers_data_path = data_base_path + "/teachers.txt";
    std::ifstream teacher_file;
    teacher_file.open(teachers_data_path);
    std::string line;
    int idx = 1;
    while (std::getline(teacher_file, line)){
        // splitting line
        std::vector<std::string> splited = split(line, ' ');
        std::shared_ptr<Teacher> t = std::make_shared<Teacher>(splited);
        t->set_id(idx);
        teachers[{splited[0], splited[1]}] = t;
        teachers_vec.push_back(t);
        idx++;
    }
}

// loading student relations
void School::load_student_relations(std::string &data_base_path) {
    std::string line;
    for (auto st : students){
        int id = st.second->get_id();
        std::string student_data_file = data_base_path + "/students_data/" + std::to_string(id) + ".txt";
        std::ifstream student_data;
        student_data.open(student_data_file);

        // loading teacher information
        while (std::getline(student_data, line)){
            int teacher_id = std::stoi(line);
            st.second->add_teacher(teacher_id);
        }
    }
}

// loading teacher relations
void School::load_teacher_relations(std::string &data_base_path) {
    for (auto t : teachers){
        int id = t.second->get_id();
        std::string teacher_data_file = data_base_path + "/teachers_data/" + std::to_string(id) + "/";

        for (auto const& dir_entry : std::filesystem::directory_iterator{teacher_data_file}){
//            std::cout << dir_entry.path() << '\n';
            auto splited = split(dir_entry.path(), '/');
            if (splited.back() == "subject.txt"){
                std::ifstream sbj;
                sbj.open(dir_entry.path());
                std::string name;
                std::getline(sbj, name);
                t.second->set_subject(name);
            }else{
                // it is student information
                std::string name = split(splited.back(), '.')[0];
                t.second->add_student(std::stoi(name));
                std::ifstream grades;
                grades.open(dir_entry.path());
                std::string line;
                std::getline(grades, line);
                auto gr = split(line, ' ');
                std::vector<int> gr_int;
                for (int i = 0; i < gr.size(); i++){
                    gr_int.push_back(std::stoi(gr[i]));
                }
                t.second->add_grade(gr_int);
            }
        }
    }
}

// loading database
void School::load_data_base(std::string &data_base_path) {

    // Reading student data from database
    load_student_data(data_base_path);

    // Reading teacher data from database
    load_teacher_data(data_base_path);

    // loading information of all teachers of a student
    load_student_relations(data_base_path);

    // loading information of all students of a teacher
    load_teacher_relations(data_base_path);
}

// processing teacher query
void School::process_teacher_query(std::shared_ptr<Human> &human) {
    while (true) {
        std::cout << "You can\n";
        std::cout << "1. see grades\n";
        //TODO more features
//            std::cout << "1. add student\n";
//            std::cout << "2. add grade\n";
        std::cout << "2. quit\n";
        std::cout << "please enter the command id: ";
        int command_id;
        std::cin >> command_id;
        if (command_id == 1){
            auto stds = human->get_relations();
            std::cout << "Choose a student from the list\n";
            for (int i = 0; i < stds.size(); i++){
                std::cout << stds[i] << ". " << students_vec[stds[i] - 1]->get_name() << ' ' << students_vec[stds[i] - 1]->get_surname() << '\n';
            }
            int idx;
            std::cin >> idx;
            bool ok = false;
            int pos = -1;
            for (int i = 0; i < stds.size(); i++){
                if (stds[i] == idx){
                    ok = true;
                    pos = i;
                    break;
                }
            }
            if (!ok){
                std::cout << "Illegal command, try again.\n";
                continue;
            }
            std::cout << "The grades of " << students_vec[idx - 1]->get_name() << ' ' << students_vec[idx - 1]->get_surname() << '\n';
            auto grds = teachers_vec[human->get_id() - 1]->get_grades()[pos];
            for (auto gr : grds)
                std::cout << gr << ' ';
            std::cout << '\n';
        }else if (command_id == 2){
            break;
        }else {
            std::cout << "Illegal command, try again.\n";
        }
    }
}

// processing student query
void School::process_student_query(std::shared_ptr<Human> &human) {
    while (true) {
        // TODO more features
        std::cout << "You can\n";
        std::cout << "1. see grade\n";
        std::cout << "2. quit\n";
        std::cout << "please enter the command id: ";
        int command_id;
        std::cin >> command_id;
        if (command_id == 1){
            auto tchrs = human->get_relations();
            for (auto t_id : tchrs){
                auto tchrs_grades = teachers_vec[t_id - 1]->get_grades();
                std::cout << "Grades for subject " << teachers_vec[t_id - 1]->get_subject() << ".\n";
                auto stds = teachers_vec[t_id - 1]->get_relations();
                int pos = -1;
                for (int p = 0; p < stds.size(); p++){
                    if (stds[p] == human->get_id()){
                        pos = p;
                        break;
                    }
                }
                for (auto grd : tchrs_grades[pos]){
                    std::cout << grd << ' ';
                }
                std::cout << '\n';
            }
        }else if (command_id == 2){
            break;
        }else{
            std::cout << "Illegal command, try again.\n";
        }
    }
}

// run main application
void School::run(std::string &data_base_path) {
    load_data_base(data_base_path);

    bool is_teacher = false;
    std::shared_ptr<Human> human;

    std::string login, password;
    while (true){
        std::cout << "Please enter login and password\n1.Login -> ";
        std::cin >> login;
        std::cout << "2.Password -> ";
        std::cin >> password;
        if (teachers.find({login, password}) != teachers.end()){
            is_teacher = true;
            human = std::make_shared<Teacher>(*teachers[{login, password}]);
            break;
        }else if (students.find({login, password}) != students.end()){
            human = std::make_shared<Student>(*students[{login, password}]);
            break;
        }else{
            std::cout << "Wrong login or password, try again!\n";
        }
    }

    std::cout << "Welcome to our online class system " <<
              (is_teacher ? "teacher \n" : "student \n") <<
              human->get_name() << ' ' << human->get_surname() << '\n';

    /* testing
    for (int i = 0; i < teachers_vec.size(); i++){
        std::cout << teachers_vec[i]->get_name() << '\n';
        std::cout << teachers_vec[i]->get_surname() << '\n';
        std::cout << teachers_vec[i]->get_sex() << '\n';
        std::cout << teachers_vec[i]->get_age() << '\n';
        std::cout << teachers_vec[i]->get_id() << '\n';
        std::cout << teachers_vec[i]->get_subject() << '\n';

        auto sdts = teachers_vec[i]->get_students();
        auto grds = teachers_vec[i]->get_grades();

        for (int p = 0; p < sdts.size(); p++){
            std::cout << sdts[p] << '\n';
            for (int j = 0; j < grds[p].size(); j++){
                std::cout << grds[p][j] << ' ';
            }
            std::cout << '\n';
        }
    }
     */

    if (is_teacher) {
        process_teacher_query(human);
    }else{
        process_student_query(human);
    }

}