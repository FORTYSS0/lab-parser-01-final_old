// Copyright 2020 Your Name <your_email>

#include <gtest/gtest.h>
#include "parser-lab-1.hpp"

TEST(Example, EmptyTest) {
    EXPECT_TRUE(true);
}

TEST(Check_WFile, Opening){
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
  string File = "Students.json";
  std :: ofstream students;
  students.open(File);
  students << string_t;
  students.close();
  bool flag = input(File);
  EXPECT_TRUE(flag);
}
TEST(Check_WFile, Emptynis) {
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
  std::vector<Student> student = parser(string_t, len) ;
  string File = "Students.json";
  std :: ofstream students;
  students.open(File);
  students << string_t;
  students.close();
  bool statement = input(File);
  std :: stringstream out;
  std::string s =  "json"+File+" the file is empty";
  EXPECT_TRUE(statement&&(s==out.str()));
}
TEST(Check_WFile, Arrayning) {
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
  std::vector<Student> student = parser(string_t, len) ;
  bool flag = items_is_arry();
  EXPECT_TRUE(flag);
}
TEST(Check_Work_Of_File, Equalityning) {
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
  std::vector<Student> student = parser(string_t, len) ;
  bool statement = j.file_equalityning();
  EXPECT_TRUE(statement);
}
//Errors_File
TEST(Check_Errors_Of_File, Opening_bad) {
  string jsonPath_test_false = "../sources/Students_bad.jso";
  string err_res = "Couldn't open json file";
  JsonParser j;
  try{
    j.file_opening(jsonPath_test_false);
  } catch (std::runtime_error& error) {
    EXPECT_EQ(error.what(), err_res);
  }
}
TEST(Check_Errors_Of_File, Emptynis_bad) {
  string string_f =\
R"({
})";
  string err_res = "Your json file is empty";
  size_t len[4] = {11, 3, 3, 11};
  std::vector<Student> student = parser(string_f, len) ;
  try{
    j.file_emptynis();
  } catch (std::runtime_error& error) {
    EXPECT_EQ(error.what(), err_res);
  }
}
TEST(Check_Errors_Of_File, Arrayning_bad) {
  string string_f =\
R"({
  "items": null,
  "_meta": {
    "count": 3
  }
})";
  string err_res = "The items field is not an array";
  size_t len[4] = {11, 3, 3, 11};
  std::vector<Student> student = parser(string_f, len) ;
  try{
    j.file_arrayning();
  } catch (std::runtime_error& error) {
    EXPECT_EQ(error.what(), err_res);
  }
}
TEST(Check_Errors_Of_File, Equalityning_bad) {
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
  string err_res = "The data in _meta is not"
                   " equal to the length of the items array";
  size_t len[4] = {11, 3, 3, 11};
  std::vector<Student> student = parser(string_f, len) ;
  try{
    j.file_equalityning();
  } catch (std::runtime_error& error) {
    EXPECT_EQ(error.what(), err_res);
  }
}
//Length
TEST(Check_Length, Count_Max_Length) {
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
  std::vector<Student> student = parser(string_t, len) ;
  j.extraction_data_from_json();
  j.maxLength();
  int nMax_test = j.get_nMax();
  int gMax_test = j.get_gMax();
  int dMax_test = j.get_dMax();
  EXPECT_EQ(nMax_test, 13);
  EXPECT_EQ(gMax_test, 6);
  EXPECT_EQ(dMax_test, 7);
}
TEST(Check_Length, Count_Max_Length_Extra_Debt) {
  const char* string_t =\
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
      "debt": "Computer Language"
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
  std::vector<Student> student = parser(string_t, len) ;
  j.extraction_data_from_json();
  j.maxLength();
  int nMax_test = j.get_nMax();
  int gMax_test = j.get_gMax();
  int dMax_test = j.get_dMax();
  EXPECT_EQ(nMax_test, 13);
  EXPECT_EQ(gMax_test, 6);
  EXPECT_EQ(dMax_test, 17);
}
//Struct
TEST(Check_Enter, Enter_to_struct) {
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
  std::vector<Student> student = parser(string_t, len) ;
  j.extraction_data_from_json();
  j.maxLength();
  bool statement = j.enter();
  EXPECT_TRUE(statement);
}
//Struct_False
TEST(Check_Struct_False_Variants, Check_group) {
  string string_f1 =\
R"({
  "items": [
    {
      "name": "Ivanov Petr",
      "group": 10.39,
      "avg": "4.25",
      "debt": null
    },
    {
      "name": "Sidorov Ivan",
      "group": 31,
      "avg": 4,
      "debt": "C++"
    }
  ],
  "_meta": {
    "count": 2
  }
})";
  string string_f2 =\
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
      "group": [
        "1",
        "2",
        "3"
      ],
      "avg": 4,
      "debt": "C++"
    }
  ],
  "_meta": {
    "count": 2
  }
})";
  string string_f3 =\
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
      "group": null,
      "avg": 4,
      "debt": "C++"
    }
  ],
  "_meta": {
    "count": 2
  }
})";
  string err_res = "Invalid data type in the group field";
  size_t len[4] = {11, 3, 3, 11};
  std::vector<Student> student = parser(string_f1, len) ;
  j.extraction_data_from_json();
  j.maxLength();
  try{
    j.enter();
  } catch (std::runtime_error& error) {
    EXPECT_EQ(error.what(), err_res);
  }
  std::vector<Student> student2 = parser(string_f2, len) ;
  try{
    j.enter();
  } catch (std::runtime_error& error) {
    EXPECT_EQ(error.what(), err_res);
  }
  std::vector<Student> student3 = parser(string_f3, len) ;
  try{
    j.enter();
  } catch (std::runtime_error& error) {
    EXPECT_EQ(error.what(), err_res);
  }
}
TEST(Check_Struct_False_Variants, Check_avg) {
  string string1_test_false =\
R"({
  "items": [
    {
      "name": "Ivanov Petr",
      "group": "1",
      "avg": [
        "4",
        "4.34",
        "4.12"
      ],
      "debt": null
    },
    {
      "name": "Sidorov Ivan",
      "group": 31,
      "avg": 4,
      "debt": "C++"
    }
  ],
  "_meta": {
    "count": 2
  }
})";
  string string2_test_false =\
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
      "avg": null,
      "debt": "C++"
    }
  ],
  "_meta": {
    "count": 2
  }
})";
  JsonParser j;
  string err_res = "Invalid data type in the avg field";
  j.parse_string_to_json(string1_test_false);
  j.extraction_data_from_json();
  j.maxLength();
  try{
    j.enter();
  } catch (std::runtime_error& error) {
    EXPECT_EQ(error.what(), err_res);
  }
  j.parse_string_to_json(string2_test_false);
  try{
    j.enter();
  } catch (std::runtime_error& error) {
    EXPECT_EQ(error.what(), err_res);
  }
}
TEST(Check_Struct_False_Variants, Check_debt) {
  string string1_test_false =\
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
      "debt": 2.5
    }
  ],
  "_meta": {
    "count": 2
  }
})";
  string string2_test_false =\
R"({
  "items": [
    {
      "name": "Ivanov Petr",
      "group": "1",
      "avg": "4.25",
      "debt": 2
    },
    {
      "name": "Sidorov Ivan",
      "group": 31,
      "avg": 4,
      "debt": "C++"
    }
  ],
  "_meta": {
    "count": 2
  }
})";
  JsonParser j;
  string err_res = "Invalid data type in the debt field";
  j.parse_string_to_json(string1_test_false);
  j.extraction_data_from_json();
  j.maxLength();
  try{
    j.enter();
  } catch (std::runtime_error& error) {
    EXPECT_EQ(error.what(), err_res);
  }
  j.parse_string_to_json(string2_test_false);
  try{
    j.enter();
  } catch (std::runtime_error& error) {
    EXPECT_EQ(error.what(), err_res);
  }
}
//Table
TEST(Check_Work_Of_Print_Table, Check_Printable_Table) {
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
R"(|---------------|--------|-----|---------|
| name          | group  |avg  | debt    |
|---------------|--------|-----|---------|
| Ivanov Petr   | 1      |4.25 | null    |
|---------------|--------|-----|---------|
| Sidorov Ivan  | 31     |4    | C++     |
|---------------|--------|-----|---------|
| Pertov Nikita | IU8-31 |3.33 | 3 items |
|---------------|--------|-----|---------|
)";
  size_t len[4] = {11, 3, 3, 11};
  std::vector<Student> student = parser(string_t, len) ;
  j.extraction_data_from_json();
  j.maxLength();
  j.enter();
  std::stringstream ref_stream;
  j.table_print(ref_stream);
  string table_res = j.get_table_final();
  EXPECT_EQ(table_t, table_res);
}