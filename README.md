# Student and Teacher management system

## Code Structure

This is the current structure of the repository


### 1. `school.h` class contains 

```
|--- School
|   |--- private variables
|       |--- students_vec
|       |--- teachers_vec
|       |--- teachers
|       |--- students
|   |--- class methods
|       |--- load_data_base()
|       |--- load_student_data()
|       |--- load_teacher_data()
|       |--- load_student_reltions()
|       |--- load_teacher_relations()
         -----------------------------------------
        |   We use this methods to read           |
        |   School database from data_base folder |
         -----------------------------------------
|       |--- process_teacher_query()
|       |--- process_student_query()
         ------------------------------------------
        |   We use this methods to process         |
        |   teachers and students query            |
         ------------------------------------------
|       |--- run()
         ------------------------------------------
        |  We use this method as main method to    |
        |  run our application                     |
         ------------------------------------------
```

### 2. `human.h` class contains

```
|--- Human
|   |--- protected variables
|       |--- name
|       |--- surname
|       |--- sex
|       |--- age
|   |--- class methods
|       |--- set_name()
         -----------------------------
        | setter for name variable    |
         -----------------------------
|       |--- set_surname()
         -----------------------------
        | setter for surname variable |
         -----------------------------
|       |--- set_sex()
         -----------------------------
        | setter for sex variable     |
         -----------------------------
|       |--- set_age()
         -----------------------------
        | setter for age variable     |
         -----------------------------
|       |--- get_name()
         -----------------------------
        | getter for name variable    |
         -----------------------------
|       |--- get_surname()
         -----------------------------
        | getter for surname variable |
         -----------------------------
|       |--- get_sex()
         -----------------------------
        | getter for sex variable     |
         -----------------------------
|       |--- get_age()
         -----------------------------
        | getter for age variable     |
         -----------------------------
|       |--- virtual get_relations()
         -----------------------------
        | virtual method for geting   |
        | student_ids for teacher and |
        | teacher_ids for student     |
         -----------------------------
|       |--- virtual get_id()
         -----------------------------
        | virtual method for geting   |
        | Id of a human               |
         -----------------------------
```

### 3. `teacher.h` class contains

```
|--- Teacher : Human
|   |--- protected variables
|       |--- students
|       |--- grades
|       |--- subject
|       |--- login
|       |--- password
|       |--- id
|   |--- class methods
|       |--- set_login()
         -----------------------------
        | setter for login variable   |
         -----------------------------
|       |--- set_password()
         -----------------------------
        | setter for password variable|
         -----------------------------
|       |--- set_id()
         -----------------------------
        | setter for id variable      |
         -----------------------------
|       |--- get_id()
         -----------------------------
        | getter for id variable      |
         -----------------------------
|       |--- add_student()
         -----------------------------
        | adds new student id to      |
        | students variable           |
         -----------------------------
|       |--- set_subject()
         -----------------------------
        | setter for subject variabl  |
         -----------------------------
|       |--- add_grade()
         -----------------------------
        | adds new grade for          |
        | grades variable             |
         -----------------------------
|       |--- get_subject()
         -----------------------------
        | getter for subject variable |
         -----------------------------
|       |--- get_grades()
         -----------------------------
        | getter for grades variable  |
         -----------------------------
|       |--- get_relations()
         -----------------------------
        | getter for students variable|
         -----------------------------
```

### 4. `student.h` class contains

```
|--- Student : Human
|   |--- protected variables
|       |--- teachers
|       |--- login
|       |--- password
|       |--- id
|   |--- class methods
|       |--- set_login()
         -----------------------------
        | setter for login variable   |
         -----------------------------
|       |--- set_password()
         -----------------------------
        | setter for password variable|
         -----------------------------
|       |--- set_id()
         -----------------------------
        | setter for id variable      |
         -----------------------------
|       |--- get_id()
         -----------------------------
        | getter for id variable      |
         -----------------------------
|       |--- add_teacher()
         -----------------------------
        | adds new teacher id to      |
        | students variable           |
         -----------------------------
|       |--- get_relations()
         -----------------------------
        | getter for teachers variable|
         -----------------------------
```

### 5. `utils.h` class contains

```
|--- split() function for string spliting
```

## DataBase

We use database for this application in this format

```
|--- data_base
|   |--- teachers.txt
|   |--- teachers_data
|       |--- ${teacher_id}
|            |--- subject.txt
              ----------------------------------
             | subject.txt contains single line |
             | of a teachers subject            |
              ----------------------------------
|            |--- ${student_id}.txt
              ----------------------------------
             | ${student_id}.txt file contains  |
             | single line of a student grades  |
              ----------------------------------
|   |--- students.txt
|   |--- students_data
|       |--- ${student_id}.txt
         -----------------------------------
        | ${student_id}.txt file contains   |
        | the IDs of a teachers who teaches |        
        | him(her)                          |
         -----------------------------------
```

## Quick Start

```
mkdir build
cd build
cmake ..
./task
```

## Testing

### testing directory structure
```
|--- testing
|    |--- ${id}
|         |--- in.txt
|         |--- res.txt
           ----------------------------------
          | in.txt contains input            |
          | res.txt contains result to match |
           ----------------------------------
```

## About OOP relations

### IS-A relation
Our `Student` and `Teacher` classes have a IS-A relation with `Human` class.

### HAS-A relation
Our `School` class HAS-A `Teacher` and `Student` classes.

### Composite relation
We can in some point sey that `Teacher` and `Student` have a 
composite relation, because they have an ID array of each other.

## Future Work

- [ ] Adding new method for teacher for updating grades and students(add\remove) (the main functions are implemented)
- [ ] Add new method for changing data_base files, because we are only read files
- [ ] Add classes in a School and School administrator
- [ ] Add an opportunity  to change login and password (the main functions are implemented)

## Reference
- https://www.jb51.net/article/241204.htm
- https://blog.csdn.net/liuzubing/article/details/116004214
- https://www.cnblogs.com/zhengze/p/14347967.html
