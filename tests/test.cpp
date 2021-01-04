// Copyright 2020 by FORTYSS

#include <gtest/gtest.h>

#include "parser.hpp"

TEST(Example, EmptyTest) {
    EXPECT_TRUE(true);
}

TEST(WFile, Open){
  string string_t =\
R"({
  "items": [
    {
      "name": "Ivanov Petr",
      "group": "1",
      "avg": "4.25",
      "debt": null
    },
    {
      "name": "Sidorov Ivan",
      "group": 31,
      "avg": 4,
      "debt": "C++"
    },
    {
      "name": "Pertov Nikita",
      "group": "IU8-31",
      "avg": 3.33,
      "debt": [
        "C++",
        "Linux",
        "Network"
      ]
    }
  ],
  "_meta": {
    "count": 3
  }
})";
  size_t len[4] = {11, 3, 3, 11};
  json data;
  string File = "Students.json";
  std :: ofstream students;
  students.open(File, std::ios::out);
  students << string_t;
  students.close();
  std::vector<Student> student = parser(File, len, data);
  bool flag = input(File, data);
  //print(student, len);
  EXPECT_TRUE(flag);
}
TEST(WFile, Emptynis) {
  string string_t =\
R"({
  "items": [
    {
      "name": "Ivanov Petr",
      "group": "1",
      "avg": "4.25",
      "debt": null
    },
    {
      "name": "Sidorov Ivan",
      "group": 31,
      "avg": 4,
      "debt": "C++"
    },
    {
      "name": "Pertov Nikita",
      "group": "IU8-31",
      "avg": 3.33,
      "debt": [
        "C++",
        "Linux",
        "Network"
      ]
    }
  ],
  "_meta": {
    "count": 3
  }
})";
  json data;
  size_t len[4] = {11, 3, 3, 11};
  string File = "Students.json";
  std :: ofstream students;
  students.open(File, std::ios::out);
  students << string_t;
  students.close();
  std::vector<Student> student = parser(File, len, data);
  bool flag = input(File, data);
  EXPECT_TRUE(flag);
}
TEST(WFile, Array) {
  string string_t =\
R"({
  "items": [
    {
      "name": "Ivanov Petr",
      "group": "1",
      "avg": "4.25",
      "debt": null
    },
    {
      "name": "Sidorov Ivan",
      "group": 31,
      "avg": 4,
      "debt": "C++"
    },
    {
      "name": "Pertov Nikita",
      "group": "IU8-31",
      "avg": 3.33,
      "debt": [
        "C++",
        "Linux",
        "Network"
      ]
    }
  ],
  "_meta": {
    "count": 3
  }
})";
  json data;
  size_t len[4] = {11, 3, 3, 11};
  string File = "Students.json";
  std :: ofstream students;
  students.open(File, std::ios::out);
  students << string_t;
  students.close();
  std::vector<Student> student = parser(File, len, data);
  bool flag = input(File, data);
  EXPECT_TRUE(flag);
/*
  size_t len[4] = {11, 3, 3, 11};
  std::vector<Student> student = parser(string_t, len);
  string File = "Students.json";
  std :: ofstream students;
  students.open(File, std::ios::out);
  students << string_t;
  students.close();
  bool flag = input(File);
  EXPECT_TRUE(flag);*/
}
TEST(WFile, Equalit) {
  string string_t =\
R"({
  "items": [
    {
      "name": "Ivanov Petr",
      "group": "1",
      "avg": "4.25",
      "debt": null
    },
    {
      "name": "Sidorov Ivan",
      "group": 31,
      "avg": 4,
      "debt": "C++"
    },
    {
      "name": "Pertov Nikita",
      "group": "IU8-31",
      "avg": 3.33,
      "debt": [
        "C++",
        "Linux",
        "Network"
      ]
    }
  ],
  "_meta": {
    "count": 3
  }
})";
  json data;
  size_t len[4] = {11, 3, 3, 11};
  string File = "Students.json";
  std :: ofstream students;
  students.open(File, std::ios::out);
  students << string_t;
  students.close();
  std::vector<Student> student = parser(File, len, data);
  bool flag = input(File, data);
  EXPECT_TRUE(flag);
}

TEST(EFile, Open_false) {
  json data;
  string FileF = "../sources/Student_false.jso";
  string err = "There is no file with this name";
  try{
    input(FileF, data);
  } catch (std::runtime_error& error) {
    EXPECT_EQ(error.what(), err);
  }
}
TEST(EFile, Empt_false) {
  string string_f =\
R"({
})";
  json data;
  size_t len[4] = {11, 3, 3, 11};
  string FileF = "Student_false.json";
  std :: ofstream students;
  students.open(FileF, std::ios::out);
  students << string_f;
  students.close();

  string err = "json " + FileF + " the file is empty";
  try{
    std::vector<Student> student = parser(FileF, len, data);
    input(FileF, data);
  } catch (std::runtime_error& error) {
    EXPECT_EQ(error.what(), err);
  }
}
TEST(EFile, Array_false) {
  string string_f =\
R"({
  "items": null,
  "_meta": {
    "count": 3
  }
})";
  json data;
  size_t len[4] = {11, 3, 3, 11};
  string FileF = "Student_false.json";
  std :: ofstream students;
  students.open(FileF, std::ios::out);
  students << string_f;
  students.close();
  string err = "The items field is not an array";
  try{
    std::vector<Student> student = parser(FileF, len, data);
    input(FileF, data);
  } catch (std::runtime_error& error) {
    EXPECT_EQ(error.what(), err);
  }
}
TEST(EFile, Equalit_false) {
  string string_f =\
R"({
  "items": [
    {
      "name": "Ivanov Petr",
      "group": "1",
      "avg": "4.25",
      "debt": null
    },
    {
      "name": "Sidorov Ivan",
      "group": 31,
      "avg": 4,
      "debt": "C++"
    },
    {
      "name": "Pertov Nikita",
      "group": "IU8-31",
      "avg": 3.33,
      "debt": [
        "C++",
        "Linux",
        "Network"
      ]
    }
  ],
  "_meta": {
    "count": 4
  }
})";
  json data;
  size_t len[4] = {11, 3, 3, 11};
  string FileF = "Student_false.json";
  std :: ofstream students;
  students.open(FileF, std::ios::out);
  students << string_f;
  students.close();
  string err =
      "The data in _meta is not equal to the length of the items array";
  try{
    std::vector<Student> student = parser(FileF, len, data);
    input(FileF, data);
  } catch (std::runtime_error& error) {
    EXPECT_EQ(error.what(), err);
  }
}

TEST(Table, Print_Table) {
  string string_t =\
R"({
  "items": [
    {
      "name": "Ivanov Petr",
      "group": "1",
      "avg": "4.25",
      "debt": null
    },
    {
      "name": "Sidorov Ivan",
      "group": 31,
      "avg": 4,
      "debt": "C++"
    },
    {
      "name": "Pertov Nikita",
      "group": "IU8-31",
      "avg": 3.33,
      "debt": [
        "C++",
        "Linux",
        "Network"
      ]
    }
  ],
  "_meta": {
    "count": 3
  }
})";
  string table_t =\
R"(| name            | group     | avg       | debt          |
|-----------------|-----------|-----------|---------------|
| Ivanov Petr     | 1         | 4.25      | null          |
|-----------------|-----------|-----------|---------------|
| Sidorov Ivan    | 31        | 4         | C++           |
|-----------------|-----------|-----------|---------------|
| Pertov Nikita   | IU8-31    | 3.33      | 3 item        |
|-----------------|-----------|-----------|---------------|)";
  json data;
  size_t len[4] = {11, 3, 3, 11};
  string FileF = "Student.json";
  std :: ofstream students;
  students.open(FileF, std::ios::out);
  students << string_t;
  students.close();
  std::vector<Student> student = parser(FileF, len, data);
  print(student, len);
  std::string table_out = print(student, len);

  //EXPECT_TRUE(true);
  //std::cout << table_t;
  //std::string table_origin = ;
  EXPECT_EQ(table_out, table_t);
}
